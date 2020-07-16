#pragma once
#include "graphics.h"

ref class App sealed : public Windows::ApplicationModel::Core::IFrameworkView
{
public:
	virtual void Initialize(Windows::ApplicationModel::Core::CoreApplicationView^ av);
	virtual void SetWindow(Windows::UI::Core::CoreWindow^ win);
	virtual void Load(Platform::String^ entrypoint);
	virtual void Run();
	virtual void Uninitialize();

	void OnActivated(Windows::ApplicationModel::Core::CoreApplicationView^ av, Windows::ApplicationModel::Activation::IActivatedEventArgs^ args);

private:
	bool m_closed;
	Graphics gfx;
};

ref class AppSource sealed : Windows::ApplicationModel::Core::IFrameworkViewSource
{
public:
	virtual Windows::ApplicationModel::Core::IFrameworkView^ CreateView() { return ref new App(); }
};