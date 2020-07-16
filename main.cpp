#include "pch.h"
#include "app.h"

[Platform::MTAThreadAttribute]
int main(Platform::Array<Platform::String^>^ args)
{ 
	Windows::ApplicationModel::Core::CoreApplication::Run(ref new AppSource());
	return 0;
}