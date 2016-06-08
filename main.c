#include <stdio.h>
#include <stdlib.h>

#include "iothub_client.h"
#include "iothubtransportamqp.h"

static const char *connectionString = "HostName=dev-chargesync.azure-devices.net;DeviceId=Damien;SharedAccessKey=fn7pPYr+VX4UvH7dEukh8SkqFDAMcZLAkmmMRJbEx9o=";

int main()
{
	IOTHUB_CLIENT_HANDLE iotHubClientHandle;
	if ((iotHubClientHandle = IoTHubClient_CreateFromConnectionString(connectionString, AMQP_Protocol)) == NULL)
	{
		printf("Failed to instantiate iot hub\n");
	}
	else
	{
		printf("Successfully connected to iot hub\n");
	}

	(void)printf("Press any key to exit the application\n");
	(void)getchar();

	IoTHubClient_Destroy(iotHubClientHandle);

	return 0;
}
