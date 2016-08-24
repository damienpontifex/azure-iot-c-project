#include "iot_sample.h"

int main(int argc, char* argv[])
{
//	cout << argv[0] << " Version " << iot_sample_VERSION_MAJOR << "." << iot_sample_VERSION_MINOR << '\n';

//	if (argc != 2)
//	{
//		cout << "Provide connection string as first parameter" << '\n';
//		exit(EXIT_FAILURE);
//	}

    const char *connectionString = "HostName=dev-chargesync.azure-devices.net;DeviceId=Damien;SharedAccessKey=fn7pPYr+VX4UvH7dEukh8SkqFDAMcZLAkmmMRJbEz9o=";

	iot_sample_run(connectionString);

	return 0;
}
