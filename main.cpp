#include <iostream>

#include "iothub_client.h"
#include "iothubtransportamqp.h"

static const char *connectionString = "[connection string]";

int main()
{
	IOTHUB_CLIENT_HANDLE iotHubClientHandle;
	if ((iotHubClientHandle = IoTHubClient_CreateFromConnectionString(connectionString, AMQP_Protocol)) == NULL)
	{
		std::cout << "Failed to instantiate iot hub" << std::endl;
	}
	else
	{
		std::cout << "Successfully connected to iot hub" << std::endl;
	}

	std::cout << "Press any key to exit the application" << std::endl;

	std::getchar();

	IoTHubClient_Destroy(iotHubClientHandle);

	return 0;
}
