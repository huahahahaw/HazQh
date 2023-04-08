#pragma once

#ifdef HAZQH_PLATFORM_WINDOWS

extern HazQh::Applicaiton* HazQh::CreateApplication();

int main(int* arc,char** arv)
{
	printf("start Run!");
	HazQh::Log::init();

	//log test code 
	HZ_CORE_ERROR("Initialized Log!");
	int a = 2;
	char c = 'x';
	HZ_WARN("Hello!,var = {0},and var 2 = {1}",a,c);

	
	
	auto app = HazQh::CreateApplication();
	app->Run();
	delete app;
}
#endif