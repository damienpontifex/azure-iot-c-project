#include <iostream>

using namespace std;

#include "iot_sample.h"
#include "iothub_client.h"
#include "iothubtransportamqp.h"

int main(int argc, char* argv[])
{
	cout << argv[0] << " Version " << iot_sample_VERSION_MAJOR << "." << iot_sample_VERSION_MINOR << '\n';

	if (argc != 2)
	{
		cout << "Provide connection string as first parameter" << '\n';
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
