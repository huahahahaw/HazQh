#pragma once

#ifdef HAZQH_PLATFORM_WINDOWS

extern HazQh::Applicaiton* HazQh::CreateApplication();

int main(int* arc,char** arv)
{
	printf("start Run!");
	auto app = HazQh::CreateApplication();
	app->Run();
	delete app;
}
#endif