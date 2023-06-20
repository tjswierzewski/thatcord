#include <string>

#define BASE_URL "https://discord.com/api"

class ThatCord
{
private:
    std::string BaseUrl;
    std::string GetGatewayURL();

public:
    ThatCord();
    ~ThatCord();
};
