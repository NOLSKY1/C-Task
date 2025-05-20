#include <iostream>
#include "ApiClient/ApiClient.h"

int main() {
    // Initialize the API client
    if (!ApiClient::Initialize()) {
        std::cout << "Failed to initialize API client" << std::endl;
        return 1;
    }

    try {
        std::string token = "your_sanctum_token";  // or "" if public route
        std::string jsonData = "{\"username\":\"naoufal1234\"}";
        std::string endpoint = "http://your-api-endpoint.com/api/endpoint";  // Replace with your actual API endpoint

        std::string postResponse = ApiClient::Post(endpoint, jsonData, token);
        std::cout << "POST Response: " << postResponse << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Cleanup
    ApiClient::Cleanup();
    return 0;
}
