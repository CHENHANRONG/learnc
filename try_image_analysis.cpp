#include "image_classify.h"

//set appid/ak/sk
std::string app_id = "";
std::string api_key = "";
std::string secret_key = "";

aip::Imageclassify client(app_id, api_key, secret_key);

int main()
{
    std::string image;
    // int x = aip::get_file_content("/home/chen/Downloads/1498121134.jpg", &image);
    int x = aip::get_file_content("/home/chen/Downloads/123.jpg", &image);

    //call car reg
    // Json::Value result = client.car_detect(image, aip::null);
    std::map<std::string, std::string> options;
    options["top_num"] = "3";
    options["baike_number"] = "5";
    Json::Value result = client.car_detect(image, options);

    return 0;
}
