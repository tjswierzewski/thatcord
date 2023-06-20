#include "HTTPRequest.hpp"

namespace net = boost::asio;    // from <boost/asio.hpp>
namespace beast = boost::beast; // from <boost/beast.hpp>
namespace http = beast::http;   // from <boost/beast/http.hpp>
using tcp = net::ip::tcp;       // from <boost/asio/ip/tcp.hpp>

HTTPRequest::HTTPRequest(std::string baseUrl)
{
    std::unique_ptr<beast::tcp_stream> s(new beast::tcp_stream(ioc));
    stream = std::move(s);
    hostUrl = baseUrl;
    if (hostUrl.at(4) == 's')
    {
        port = "443";
    }
    else
    {
        port = "80";
    }
}

void HTTPRequest::Connect()
{
    tcp::resolver resolver(ioc);
    // beast::error er;
    auto const results = resolver.resolve(hostUrl.c_str(), port.c_str());
    stream->connect(results);
}

std::string HTTPRequest::GetPort()
{
    return port;
}