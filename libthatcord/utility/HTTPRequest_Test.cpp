#include "HTTPRequest.hpp"

#include <gtest/gtest.h>
#include <string>

TEST(UtilityTest, HTTPPort)
{
    HTTPRequest request("http://www.google.com");
    std::string test = "80";
    ASSERT_STREQ(request.GetPort().c_str(), test.c_str());
}

TEST(UtilityTest, HTTPSPort)
{
    HTTPRequest request("https://www.google.com");
    std::string test = "443";
    ASSERT_STREQ(request.GetPort().c_str(), test.c_str());
}