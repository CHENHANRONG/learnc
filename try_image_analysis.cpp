#include "image_classify.h"

//set appid/ak/sk
std::string app_id = "11726882";
std::string api_key = "8msWtxapbtZknv95YgmqE5XY";
std::string secret_key = "MghF6DCifoIl5zWSXiupLQdno0Wo7q52";

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
