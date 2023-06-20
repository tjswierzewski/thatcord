#include <string>
#include <memory>
#include <boost/beast/core.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>

namespace net = boost::asio;    // from <boost/asio.hpp>
namespace beast = boost::beast; // from <boost/beast.hpp>
namespace http = beast::http;   // from <boost/beast/http.hpp>
using tcp = net::ip::tcp;       // from <boost/asio/ip/tcp.hpp>

class HTTPRequest
{
private:
    std::string port;
    std::string hostUrl;
    net::io_context ioc;
    std::unique_ptr<beast::tcp_stream> stream;

    void Connect();

public:
    HTTPRequest(std::string baseUrl);
    // ~HTTPRequest();
    // void Get(std::string relativeUrL);
    // void Post(std::string relativeUrL);
    std::string GetPort();
};
