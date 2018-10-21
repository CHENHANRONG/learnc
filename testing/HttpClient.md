
```Java

import org.apache.http.HttpEntity;
import org.apache.http.HttpHost;
import org.apache.http.HttpResponse;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.CloseableHttpResponse;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.config.Registry;
import org.apache.http.config.RegistryBuilder;
import org.apache.http.conn.socket.ConnectionSocketFactory;
import org.apache.http.conn.socket.PlainConnectionSocketFactory;
import org.apache.http.conn.ssl.SSLConnectionSocketFactory;
import org.apache.http.entity.ByteArrayEntity;
import org.apache.http.entity.StringEntity;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClientBuilder;
import org.apache.http.impl.client.HttpClients;
import org.apache.http.impl.conn.PoolingHttpClientConnectionManager;
import org.apache.http.ssl.SSLContexts;
import org.apache.http.util.EntityUtils;
import org.json.JSONObject;
import org.testng.Assert;
import org.testng.annotations.*;

import javax.net.ssl.HttpsURLConnection;
import javax.net.ssl.KeyManager;
import javax.net.ssl.KeyManagerFactory;
import javax.net.ssl.SSLContext;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.security.KeyStore;

import static org.testng.Assert.assertEquals;
import static org.testng.Assert.assertNotNull;

public class UserTestWithoutStructure {

    private String email = RandomStringUtils.randomAlphabetic(7) + "@gmail.com";
    private HttpClient client;
    private HttpResponse httpResponse;

    @BeforeTest
    public void beforeTest() {
//        client = new DefaultHttpClient();
        client = HttpClientBuilder.create().build();;
    }


    @DataProvider(name = "positiveTestData")
    public Object[][] positiveTestData() {
        return new Object[][] {
                {email, "password", "name", 200}
        };
    }

    @Test(dataProvider = "positiveTestData")
    public void registerUserPositiveTest(String email, String password, String name, int expectedCode) throws Exception {
        HttpPost postRequest = new HttpPost(ApiSettings.API_URL + "v1/users/register");

        postRequest.addHeader("application-id", ApiSettings.APPLICATION_ID_VALUE);
        postRequest.addHeader("secret-key", ApiSettings.REST_SECRET_KEY_VALUE);
        postRequest.addHeader("Content-Type", "application/json");
        postRequest.addHeader("application-type", "REST");

//        String body = "{\"email\" : \"" + email + "\", \"password\" : \""
//                + password + "\", \"name\" : \"" + name + "\"}";
        JSONObject main = new JSONObject();
        main.put("email", email);
        main.put("password", password);
        main.put("name", name);
        String body = main.toString();

        StringEntity params = new StringEntity(body);
        postRequest.setEntity(params);

        httpResponse = client.execute(postRequest);
        assertEquals(httpResponse.getStatusLine().getStatusCode(), expectedCode,
                "Wrong status code: Server made incorrect response.");

        //result json
        /*
        InputStream content = httpResponse.getEntity().getContent();  // response content
        InputStreamReader reader = new InputStreamReader(content);
        BufferedReader bReader = new BufferedReader(reader);
        StringBuffer result = new StringBuffer();
        String line = "";
        while ((line = bReader.readLine()) != null) {
            result.append(line);
        }
        result.toString();

        //todo: check that result contains correct data
        //(use JsonObject for parsing result in json format)
        */



        // Convert the response to a String format
        String result = EntityUtils.toString(httpResponse.getEntity());

        // Convert the result as a String to a JSON object
        JSONObject jo = new JSONObject(result);

        // Verify content
        String expectedValue= "xxx";
        String element = "xxx";
        assertEquals(expectedValue, jo.getString(element));
    }

    @AfterMethod
    public void afterMethod() throws IOException {
        EntityUtils.consume(httpResponse.getEntity());
    }


    public String httpsPost(String servicePath, String postData) throws IOException {
        /////////////////
        // Create SSL Client
        /////////////////

        CloseableHttpClient httpclient = null;
        HttpHost target = new HttpHost(ApiSettings.API_URL, 443, "https");

        SSLContext sslcontext = SSLContexts.createSystemDefault();
        SSLConnectionSocketFactory sslConnectionSocketFactory = new SSLConnectionSocketFactory(
                sslcontext, new String[] { "TLSv1", "SSLv3" }, null,
                SSLConnectionSocketFactory.getDefaultHostnameVerifier());

        Registry<ConnectionSocketFactory> socketFactoryRegistry = RegistryBuilder.<ConnectionSocketFactory>create()
                .register("http", PlainConnectionSocketFactory.INSTANCE)
                .register("https", sslConnectionSocketFactory)
                .build();
        PoolingHttpClientConnectionManager cm = new PoolingHttpClientConnectionManager(socketFactoryRegistry);

        httpclient = HttpClients.custom()
                .setSSLSocketFactory(sslConnectionSocketFactory)
                .setConnectionManager(cm)
                .build();

        /////////////////
        // Send POST
        /////////////////

        HttpPost httpPost = new HttpPost(servicePath);
        ByteArrayEntity postDataEntity = new ByteArrayEntity(postData.getBytes());
        httpPost.setEntity(postDataEntity);
        CloseableHttpResponse response = httpclient.execute(target, httpPost);

        /////////////////
        // Get RESPONSE
        /////////////////
        String result;

        try {
            HttpEntity entity = response.getEntity();
            result = EntityUtils.toString(entity);
            EntityUtils.consume(entity);
        } finally {
            response.close();
        }

        return result;
    }




    private static final String KEYSTOREPATH = "/clientkeystore.jks"; // or .p12
    private static final String KEYSTOREPASS = "keystorepass";
    private static final String KEYPASS = "keypass";

    KeyStore readStore() throws Exception {
        try (InputStream keyStoreStream = this.getClass().getResourceAsStream(KEYSTOREPATH)) {
            KeyStore keyStore = KeyStore.getInstance("JKS"); // or "PKCS12"
            keyStore.load(keyStoreStream, KEYSTOREPASS.toCharArray());
            return keyStore;
        }
    }
    @Test
    public void readKeyStore() throws Exception {
        assertNotNull(readStore());
    }
    @Test
    public void performClientRequest() throws Exception {
        SSLContext sslContext = SSLContexts.custom()
                .loadKeyMaterial(readStore(), KEYPASS.toCharArray()) // use null as second param if you don't have a separate key password
                .build();

        HttpClient httpClient = HttpClients.custom().setSSLContext(sslContext).build();
        HttpResponse response = httpClient.execute(new HttpGet("https://slsh.iki.fi/client-certificate/protected/"));
        assertEquals(200, response.getStatusLine().getStatusCode());
        HttpEntity entity = response.getEntity();

//        System.out.println("----------------------------------------");
//        System.out.println(response.getStatusLine());
        EntityUtils.consume(entity);
    }



    // 2nd approach

    private static void setSSLFactories(InputStream keyStream, String keystoreType, char[] keyStorePassword, char[] keyPassword) throws Exception
    {
        KeyStore keyStore = KeyStore.getInstance(keystoreType);

        keyStore.load(keyStream, keyStorePassword);

        KeyManagerFactory keyFactory =
                KeyManagerFactory.getInstance(KeyManagerFactory.getDefaultAlgorithm());

        keyFactory.init(keyStore, keyPassword);

        KeyManager[] keyManagers = keyFactory.getKeyManagers();

        SSLContext sslContext = SSLContext.getInstance("SSL");
        sslContext.init(keyManagers, null, null);
        SSLContext.setDefault(sslContext);
    }

    @Test
    public void testPlainJavaHTTPS() throws Exception {
        String httpsURL = "https://slsh.iki.fi/client-certificate/protected/";
        URL myUrl = new URL(httpsURL);
//        HttpsURLConnection conn = (HttpsURLConnection)myUrl.openConnection();

        HttpURLConnection connection = (HttpURLConnection) myUrl.openConnection();
        if (connection instanceof HttpsURLConnection) {
            ((HttpsURLConnection)connection)
                    .setSSLSocketFactory(HttpsURLConnection.getDefaultSSLSocketFactory());
//                    .setSSLSocketFactory(sc.getSSLSocketFactory());
        }



        try (InputStream is = connection.getInputStream()) {
            InputStreamReader isr = new InputStreamReader(is);
            BufferedReader br = new BufferedReader(isr);

            String inputLine;

            while ((inputLine = br.readLine()) != null) {
                System.out.println(inputLine);
            }
        }
    }


    // another approach
    @BeforeClass
    public static void setUp() {
        System.setProperty("javax.net.ssl.keyStore", "/full/path/to/clientkeystore-samepassword.jks");
        System.setProperty("javax.net.ssl.keyStorePassword", "keystorepass");
    }

    @Test
    public void testPlainJavaHTTPS3() throws Exception {
        String httpsURL = "https://slsh.iki.fi/client-certificate/protected/";
        URL myUrl = new URL(httpsURL);
        HttpsURLConnection conn = (HttpsURLConnection)myUrl.openConnection();
        try (InputStream is = conn.getInputStream()) {
            InputStreamReader isr = new InputStreamReader(is);
            BufferedReader br = new BufferedReader(isr);

            String inputLine;

            while ((inputLine = br.readLine()) != null) {
                System.out.println(inputLine);
            }
        }
    }
}

```
