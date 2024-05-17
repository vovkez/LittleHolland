#pragma once
#include <string>
#include <vector>

class NetworkConnection
{
public:
    bool open(const std::string& serverAddress);
    void send(const std::vector<char>& data);
};
