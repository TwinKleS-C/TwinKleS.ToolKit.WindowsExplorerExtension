#pragma once

// ------------------------------------------------

#include "framework.h"

// ------------------------------------------------

namespace TwinKleS::Expose::WindowsExplorerExtension {

	// ------------------------------------------------

	class BaseCommand : public RuntimeClass<RuntimeClassFlags<ClassicCom>, IExplorerCommand, IObjectWithSite> {

		// ------------------------------------------------

	protected: //

		// ------------------------------------------------

		ComPtr<IUnknown> m_site;

		// ------------------------------------------------

	public: //

		// ------------------------------------------------

		IFACEMETHODIMP GetTitle (
			_In_opt_ IShellItemArray *            items,
			_Outptr_result_nullonfailure_ PWSTR * name
		) {
			*name = nullptr;
			auto title_data = thiz.title();
			if (title_data == nullptr) {
				return S_FALSE;
			}
			auto title_s = wil::make_cotaskmem_string_nothrow(title_data);
			RETURN_IF_NULL_ALLOC(title_s);
			*name = title_s.release();
			return S_OK;
		}

		IFACEMETHODIMP GetIcon (
			_In_opt_ IShellItemArray *            unused_1,
			_Outptr_result_nullonfailure_ PWSTR * icon
		) {
			*icon = nullptr;
			auto icon_data = thiz.icon();
			if (icon_data == nullptr) {
				return E_NOTIMPL;
			}
			auto icon_s = wil::make_cotaskmem_string_nothrow(icon_data);
			RETURN_IF_NULL_ALLOC(icon_s);
			*icon = icon_s.release();
			return S_OK;
		}

		IFACEMETHODIMP GetToolTip (
			_In_opt_ IShellItemArray *            unused_1,
			_Outptr_result_nullonfailure_ PWSTR * infoTip
		) {
			*infoTip = nullptr;
			return E_NOTIMPL;
		}

		IFACEMETHODIMP GetCanonicalName (
			_Out_ GUID * guidCommandName
		) {
			*guidCommandName = GUID_NULL;
			return S_OK;
		}

		IFACEMETHODIMP GetState (
			_In_opt_ IShellItemArray * selection,
			_In_ BOOL                  okToBeSlow,
			_Out_ EXPCMDSTATE *        cmdState
		) {
			*cmdState = thiz.state(selection);
			return S_OK;
		}

		IFACEMETHODIMP Invoke (
			_In_opt_ IShellItemArray * selection,
			_In_opt_ IBindCtx *        unused_1
		) noexcept try {
			return S_OK;
		}
		CATCH_RETURN();

		IFACEMETHODIMP GetFlags (
			_Out_ EXPCMDFLAGS * flags
		) {
			*flags = thiz.flags();
			return S_OK;
		}

		IFACEMETHODIMP EnumSubCommands (
			_COM_Outptr_ IEnumExplorerCommand ** enumCommands
		) {
			*enumCommands = nullptr;
			return E_NOTIMPL;
		}

		// ------------------------------------------------

		IFACEMETHODIMP SetSite (
			_In_ IUnknown * site
		) noexcept {
			thiz.m_site = site;
			return S_OK;
		}

		IFACEMETHODIMP GetSite (
			_In_ REFIID          riid,
			_COM_Outptr_ void ** site
		) noexcept {
			return thiz.m_site.CopyTo(riid, site);
		}

		// ------------------------------------------------

		virtual auto title (
		) -> LPCWSTR {
			return nullptr;
		}

		virtual auto icon (
		) -> LPCWSTR {
			return nullptr;
		}

		virtual auto state (
			_In_opt_ IShellItemArray * selection
		) -> EXPCMDSTATE {
			return ECS_ENABLED;
		}

		virtual auto flags (
		) -> EXPCMDFLAGS {
			return ECF_DEFAULT;
		}

		// ------------------------------------------------

	};

	// ------------------------------------------------

	class SeparatorCommand : public BaseCommand {

		// ------------------------------------------------

	public: //

		// ------------------------------------------------

		virtual auto flags (
		) -> EXPCMDFLAGS override {
			return ECF_ISSEPARATOR;
		}

		// ------------------------------------------------

	};

	// ------------------------------------------------

	inline auto get_selection_path (
		IShellItemArray * selection
	) -> std::vector<std::wstring> {
		std::vector<std::wstring> result{};
		if (selection) {
			DWORD count;
			selection->GetCount(&count);
			if (count > 0) {
				result.reserve(count);
				for (DWORD i = 0; i < count; ++i) {
					IShellItem * item;
					if (SUCCEEDED(selection->GetItemAt(i, &item))) {
						LPWSTR s;
						item->GetDisplayName(SIGDN_FILESYSPATH, &s);
						item->Release();
						result.emplace_back(s);
						CoTaskMemFree(s);
					}
				}
			}
		}
		return result;
	}

	// ------------------------------------------------

}

// ------------------------------------------------
