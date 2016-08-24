#include <iostream>

#include "iothub_client.h"
#include "iothubtransportamqp.h"

using namespace std;

void iot_sample_run(const char *connectionString)
{
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
}