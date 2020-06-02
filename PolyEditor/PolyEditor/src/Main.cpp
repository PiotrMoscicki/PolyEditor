#include <iostream>

#include <qapplication.h>
#include <pp/PolyPlugin.hpp>
#include <WindowsManagerAPI.hpp>
#include <windows.h>

//------------------------------------------------------------------------------------------------------------------------------------------
int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	QCoreApplication::setOrganizationName("QtProject");
	QCoreApplication::setApplicationName("Application Example");
	QCoreApplication::setApplicationVersion(QT_VERSION_STR);

	pp::PluginsContainer container;
	char ownPth[MAX_PATH];

	HMODULE hModule = GetModuleHandle(NULL);
	if (hModule != NULL)
	{
		GetModuleFileName(hModule, ownPth, (sizeof(ownPth)));
		container.load(std::filesystem::path(ownPth).parent_path(), false);
	}

	std::unique_ptr<ed::windowsManager::IManager> windowsManager;

	std::optional<std::unique_ptr<ed::windowsManager::IManager>> windowsManagerCreationResult
		= container.getRouter()->processIntent(pt::CreateManagerIntent<ed::windowsManager::IManager>());
	if (windowsManagerCreationResult.has_value())
		windowsManager = std::move(windowsManagerCreationResult.value());
	else
		return -1;

	auto topLevelWindow = windowsManager->openTopLevelWindow();
	topLevelWindow->openSubEditorWindow();
	topLevelWindow->openSubEditorWindow();
	topLevelWindow->openSubEditorWindow();
	topLevelWindow->openSubEditorWindow();

	int result = app.exec();

	return result;
}


