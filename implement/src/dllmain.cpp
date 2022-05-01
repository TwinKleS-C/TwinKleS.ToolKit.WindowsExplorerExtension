// ------------------------------------------------

#include "method_invoke_command_expose.hpp"

// ------------------------------------------------

BOOL APIENTRY DllMain (
	HMODULE hModule,
	DWORD   ul_reason_for_call,
	LPVOID  lpReserved
) {
	switch (ul_reason_for_call) {
		case DLL_PROCESS_ATTACH :
		case DLL_THREAD_ATTACH :
		case DLL_THREAD_DETACH :
		case DLL_PROCESS_DETACH :
			break;
	}
	return TRUE;
}

STDAPI DllCanUnloadNow (
) {
	return Module<InProc>::GetModule().GetObjectCount() == 0 ? S_OK : S_FALSE;
}

STDAPI DllGetClassObject (
	_In_ REFCLSID        rclsid,
	_In_ REFIID          riid,
	_COM_Outptr_ void ** instance
) {
	return Module<InProc>::GetModule().GetClassObject(rclsid, riid, instance);
}

STDAPI DllGetActivationFactory (
	_In_ HSTRING                       activatableClassId,
	_COM_Outptr_ IActivationFactory ** factory
) {
	return Module<InProc>::GetModule().GetActivationFactory(activatableClassId, factory);
}

// ------------------------------------------------

using namespace TwinKleS::Expose::WindowsExplorerExtension;

CoCreatableClass(LaunchMethodInvokeCommand);
CoCreatableClass(JSEvaluateMethodInvokeCommand);
CoCreatableClass(JSONMethodInvokeGroupCommand);
CoCreatableClass(DataMethodInvokeGroupCommand);
CoCreatableClass(PopCapPAKMethodInvokeGroupCommand);
CoCreatableClass(PopCapDZMethodInvokeGroupCommand);
CoCreatableClass(PopCapRSGPMethodInvokeGroupCommand);
CoCreatableClass(PopCapRSBMethodInvokeGroupCommand);
CoCreatableClass(AtlasMethodInvokeGroupCommand);
CoCreatableClass(PopCapTextureMethodInvokeGroupCommand);
CoCreatableClass(PopCapAnimationMethodInvokeGroupCommand);
CoCreatableClass(WwiseSoundBankMethodInvokeGroupCommand);
CoCreatableClass(WwiseEncodedMediaMethodInvokeGroupCommand);
CoCreatableClass(PopCapRTONMethodInvokeGroupCommand);
CoCreatableClass(PopCapZLibMethodInvokeGroupCommand);
CoCreatableClass(PvZ2LawnStringTextMethodInvokeGroupCommand);

CoCreatableClassWrlCreatorMapInclude(LaunchMethodInvokeCommand);
CoCreatableClassWrlCreatorMapInclude(JSEvaluateMethodInvokeCommand);
CoCreatableClassWrlCreatorMapInclude(JSONMethodInvokeGroupCommand);
CoCreatableClassWrlCreatorMapInclude(DataMethodInvokeGroupCommand);
CoCreatableClassWrlCreatorMapInclude(PopCapPAKMethodInvokeGroupCommand);
CoCreatableClassWrlCreatorMapInclude(PopCapDZMethodInvokeGroupCommand);
CoCreatableClassWrlCreatorMapInclude(PopCapRSGPMethodInvokeGroupCommand);
CoCreatableClassWrlCreatorMapInclude(PopCapRSBMethodInvokeGroupCommand);
CoCreatableClassWrlCreatorMapInclude(AtlasMethodInvokeGroupCommand);
CoCreatableClassWrlCreatorMapInclude(PopCapTextureMethodInvokeGroupCommand);
CoCreatableClassWrlCreatorMapInclude(PopCapAnimationMethodInvokeGroupCommand);
CoCreatableClassWrlCreatorMapInclude(WwiseSoundBankMethodInvokeGroupCommand);
CoCreatableClassWrlCreatorMapInclude(WwiseEncodedMediaMethodInvokeGroupCommand);
CoCreatableClassWrlCreatorMapInclude(PopCapRTONMethodInvokeGroupCommand);
CoCreatableClassWrlCreatorMapInclude(PopCapZLibMethodInvokeGroupCommand);
CoCreatableClassWrlCreatorMapInclude(PvZ2LawnStringTextMethodInvokeGroupCommand);

// ------------------------------------------------
