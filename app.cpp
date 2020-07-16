#include "pch.h"
#include "app.h"

void App::Initialize(Windows::ApplicationModel::Core::CoreApplicationView^ av)
{
	m_closed = false;

	av->Activated += ref new Windows::Foundation::TypedEventHandler<
		Windows::ApplicationModel::Core::CoreApplicationView^, 
		Windows::ApplicationModel::Activation::IActivatedEventArgs^
	>(this, &App::OnActivated);
}

void App::SetWindow(Windows::UI::Core::CoreWindow^ win)
{
	return;
}

void App::Load(Platform::String^ entrypoint)
{
	return;
}

void App::Run()
{
	Windows::UI::Core::CoreWindow^ win = Windows::UI::Core::CoreWindow::GetForCurrentThread();
	gfx.initialize();

	while (!m_closed) {
		win->Dispatcher->ProcessEvents(Windows::UI::Core::CoreProcessEventsOption::ProcessAllIfPresent);

		gfx.update();
		gfx.render();
	}
}

void App::Uninitialize()
{
	return;
}

void App::OnActivated(Windows::ApplicationModel::Core::CoreApplicationView^ av, Windows::ApplicationModel::Activation::IActivatedEventArgs^ args)
{
	Windows::UI::Core::CoreWindow::GetForCurrentThread()->Activate();
}
