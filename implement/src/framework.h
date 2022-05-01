#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#pragma once

// ------------------------------------------------

#include <windows.h>
#include <shellapi.h>
#include <wrl/module.h>
#include <wrl/implements.h>
#include <wrl/client.h>
#include <wil/resource.h>
#include <shobjidl_core.h>
#include <shellapi.h>

// ------------------------------------------------

#include <optional>
#include <vector>
#include <string>
#include <regex>
#include <filesystem>

// ------------------------------------------------

using Microsoft::WRL::RuntimeClass;
using Microsoft::WRL::RuntimeClassFlags;
using Microsoft::WRL::ClassicCom;
using Microsoft::WRL::ComPtr;
using Microsoft::WRL::Make;
using Microsoft::WRL::Module;
using Microsoft::WRL::InProc;

// ------------------------------------------------

#define thiz (*this)

// ------------------------------------------------
