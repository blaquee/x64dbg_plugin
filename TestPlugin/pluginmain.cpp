#include <Windows.h>
#include "pluginsdk\_plugins.h"

int pluginHandle = 0;
HWND hwndDlg;
int hMenu;
HMODULE hModule;
#define NAME "PluginTest"

int APIENTRY DllMain(HMODULE hModule1, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    hModule = hModule1;
    DisableThreadLibraryCalls(hModule1);
    return 1;
}

extern "C" __declspec(dllexport) bool pluginit(PLUG_INITSTRUCT* initStruct)
{
    initStruct->pluginVersion = 1;
    initStruct->sdkVersion = PLUG_SDKVERSION;
    pluginHandle = initStruct->pluginHandle;
    strcpy_s(initStruct->pluginName, NAME);
    return true;
}


extern "C" __declspec(dllexport) void plugsetup(PLUG_SETUPSTRUCT* setupStruct)
{
    hwndDlg = setupStruct->hwndDlg;
    hMenu = setupStruct->hMenu;
    _plugin_menuaddentry(hMenu, 1, "Menu 1");
    _plugin_menuaddentry(hMenu, 2, "Menu 2");
}


void handleMenu(CBTYPE cbType, void* arg1)
{
    return;
}
