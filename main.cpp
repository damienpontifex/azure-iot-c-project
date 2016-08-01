#include <iostream>

using namespace std;

#include "iothub_client.h"
#include "iothubtransportamqp.h"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Provide connection string as first parameter" << endl;
		exit(EXIT_FAILURE);
	}

	const char *connectionString = argv[1];

	IOTHUB_CLIENT_HANDLE iotHubClientHandle;
	if ((iotHubClientHandle = IoTHubClient_CreateFromConnectionString(connectionString, AMQP_Protocol)) == NULL)
	{
		cout << "Failed to instantiate iot hub" << endl;
	}
	else
	{
		cout << "Successfully connected to iot hub" << endl;
	}

	cout << "Press any key to exit the application" << endl;

	getchar();

	IoTHubClient_Destroy(iotHubClientHandle);

	return 0;
}
