#include "OpenCL.h"

#include <CL/cl.h>
#include <cstdlib>
#include <cstdio>

void listPlatforms() {
  char* info;
  size_t infoSize;
  cl_uint platformCount;
  cl_platform_id *platforms;
  const char* attributeNames[5] = { "Name", "Vendor",
                                    "Version", "Profile", "Extensions" };
  const cl_platform_info attributeTypes[5] = { CL_PLATFORM_NAME, CL_PLATFORM_VENDOR,
                                               CL_PLATFORM_VERSION, CL_PLATFORM_PROFILE, CL_PLATFORM_EXTENSIONS };
  const int attributeCount = sizeof(attributeNames) / sizeof(char*);

  // get platform count
  cl_int getPlatformIDsResult = clGetPlatformIDs(5, NULL, &platformCount);
  printf("Result: %d Platform count: %d\n", getPlatformIDsResult, platformCount);

  // get all platforms
  platforms = (cl_platform_id*) malloc(sizeof(cl_platform_id) * platformCount);
  clGetPlatformIDs(platformCount, platforms, NULL);

  // for each platform print all attributes
  for (cl_uint i = 0; i < platformCount; i++) {

    printf("\n %d. Platform \n", i+1);

    for (cl_uint j = 0; j < attributeCount; j++) {

      // get platform attribute value size
      clGetPlatformInfo(platforms[i], attributeTypes[j], 0, NULL, &infoSize);
      info = (char*) malloc(infoSize);

      // get platform attribute value
      clGetPlatformInfo(platforms[i], attributeTypes[j], infoSize, info, NULL);

      printf("  %d.%d %-11s: %s\n", i+1, j+1, attributeNames[j], info);
      free(info);

    }

    printf("\n");

  }
}
