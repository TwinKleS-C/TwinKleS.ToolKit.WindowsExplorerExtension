#pragma once

// ------------------------------------------------

#include "framework.h"
#include "base_command.hpp"
#include "method_invoke_command.hpp"

// ------------------------------------------------

namespace TwinKleS::Expose::WindowsExplorerExtension {

	// ------------------------------------------------

	namespace MethodInvokeCommandConfigList {

		// ------------------------------------------------

		inline const auto launch = MethodInvokeCommandConfig{
			.name = L"Launch",
			.type = std::nullopt,
			.rule = std::nullopt,
			.method = std::nullopt,
			.argument = LR"({})",
		};

		inline const auto js_evaluate = MethodInvokeCommandConfig{
			.name = L"JS Evaluate",
			.type = false,
			.rule = std::wregex{LR"(.+(\.js)$)", std::wregex::icase},
			.method = L"js.evaluate",
			.argument = LR"({})",
		};

		inline const auto json = MethodInvokeCommandConfigGroup{
			.name = L"JSON",
			.child = {
				{
					.name = L"格式化",
					.type = false,
					.rule = std::wregex{LR"(.+(\.json)$)", std::wregex::icase},
					.method = L"json.format",
					.argument = LR"({})",
				},
				{
					.name = L"格式化（默认格式）",
					.type = false,
					.rule = std::wregex{LR"(.+(\.json)$)", std::wregex::icase},
					.method = L"json.format",
					.argument = LR"({ """disable_trailing_comma""": """?default""", """disable_array_wrap_line""": """?default""" })",
				},
				{
					.name = L"[批处理] 格式化",
					.type = true,
					.rule = std::nullopt,
					.method = L"json.format.batch",
					.argument = LR"({})",
				},
				{
					.name = L"[批处理] 格式化（默认格式）",
					.type = true,
					.rule = std::nullopt,
					.method = L"json.format.batch",
					.argument = LR"({ """disable_trailing_comma""": """?default""", """disable_array_wrap_line""": """?default""" })",
				},
			},
			.separator = {
				2,
				2,
			},
		};

		inline const auto data = MethodInvokeCommandConfigGroup{
			.name = L"Data",
			.child = {
				{
					.name = L"Base64 编码",
					.type = false,
					.rule = std::nullopt,
					.method = L"data.base64.encode",
					.argument = LR"({})",
				},
				{
					.name = L"Base64 解码",
					.type = false,
					.rule = std::nullopt,
					.method = L"data.base64.decode",
					.argument = LR"({})",
				},
				{
					.name = L"XOR 加解密",
					.type = false,
					.rule = std::nullopt,
					.method = L"data.xor.crypt",
					.argument = LR"({})",
				},
				{
					.name = L"ZLib 压缩",
					.type = false,
					.rule = std::nullopt,
					.method = L"data.zlib.compress",
					.argument = LR"({})",
				},
				{
					.name = L"ZLib 解压",
					.type = false,
					.rule = std::nullopt,
					.method = L"data.zlib.uncompress",
					.argument = LR"({})",
				},
				{
					.name = L"MD5 计算",
					.type = false,
					.rule = std::nullopt,
					.method = L"data.hash.md5",
					.argument = LR"({})",
				},
			},
			.separator = {
				2,
				1,
				2,
				1,
			},
		};

		inline const auto popcap_pak = MethodInvokeCommandConfigGroup{
			.name = L"PopCap PAK",
			.child = {
				{
					.name = L"打包",
					.type = true,
					.rule = std::wregex{LR"(.+(\.pak)(\.package)$)", std::wregex::icase},
					.method = L"package.popcap_pak.pack",
					.argument = LR"({})",
				},
				{
					.name = L"解包",
					.type = false,
					.rule = std::wregex{LR"(.+(\.pak)$)", std::wregex::icase},
					.method = L"package.popcap_pak.unpack",
					.argument = LR"({})",
				},
				{
					.name = L"资源解包",
					.type = false,
					.rule = std::wregex{LR"(.+(\.pak)$)", std::wregex::icase},
					.method = L"package.popcap_pak.unpack_resource",
					.argument = LR"({})",
				},
				{
					.name = L"资源打包",
					.type = true,
					.rule = std::wregex{LR"(.+(\.pak)(\.resource)$)", std::wregex::icase},
					.method = L"package.popcap_pak.pack_resource",
					.argument = LR"({})",
				},
				{
					.name = L"加解密",
					.type = false,
					.rule = std::wregex{LR"(.+(\.pak)$)", std::wregex::icase},
					.method = L"package.popcap_pak.crypt",
					.argument = LR"({})",
				},
			},
			.separator = {
				2,
				2,
				1,
			},
		};

		inline const auto popcap_dz = MethodInvokeCommandConfigGroup{
			.name = L"PopCap DZ",
			.child = {
				{
					.name = L"打包",
					.type = true,
					.rule = std::wregex{LR"(.+(\.dz)(\.package)$)", std::wregex::icase},
					.method = L"package.popcap_dz.pack",
					.argument = LR"({})",
				},
				{
					.name = L"解包",
					.type = false,
					.rule = std::wregex{LR"(.+(\.dz)$)", std::wregex::icase},
					.method = L"package.popcap_dz.unpack",
					.argument = LR"({})",
				},
				{
					.name = L"资源解包",
					.type = false,
					.rule = std::wregex{LR"(.+(\.dz)$)", std::wregex::icase},
					.method = L"package.popcap_dz.unpack_resource",
					.argument = LR"({})",
				},
				{
					.name = L"资源打包",
					.type = true,
					.rule = std::wregex{LR"(.+(\.dz)(\.resource)$)", std::wregex::icase},
					.method = L"package.popcap_dz.pack_resource",
					.argument = LR"({})",
				},
			},
			.separator = {
				2,
				2,
			},
		};

		inline const auto popcap_rsgp = MethodInvokeCommandConfigGroup{
			.name = L"PopCap RSGP",
			.child = {
				{
					.name = L"打包",
					.type = true,
					.rule = std::wregex{LR"(.+(\.rsgp)(\.package)$)", std::wregex::icase},
					.method = L"package.popcap_rsgp.pack",
					.argument = LR"({})",
				},
				{
					.name = L"解包",
					.type = false,
					.rule = std::wregex{LR"(.+(\.rsgp)$)", std::wregex::icase},
					.method = L"package.popcap_rsgp.unpack",
					.argument = LR"({})",
				},
				{
					.name = L"资源解包",
					.type = false,
					.rule = std::wregex{LR"(.+(\.rsgp)$)", std::wregex::icase},
					.method = L"package.popcap_rsgp.unpack_resource",
					.argument = LR"({})",
				},
			},
			.separator = {
				2,
				1,
			},
		};

		inline const auto popcap_rsb = MethodInvokeCommandConfigGroup{
			.name = L"PopCap RSB",
			.child = {
				{
					.name = L"打包",
					.type = true,
					.rule = std::wregex{LR"(.+(\.rsb)(\.package)$)", std::wregex::icase},
					.method = L"package.popcap_rsb.pack",
					.argument = LR"({})",
				},
				{
					.name = L"解包",
					.type = false,
					.rule = std::wregex{LR"(.+(\.rsb)$)", std::wregex::icase},
					.method = L"package.popcap_rsb.unpack",
					.argument = LR"({})",
				},
				{
					.name = L"资源提取",
					.type = false,
					.rule = std::wregex{LR"(.+(\.rsb)$)", std::wregex::icase},
					.method = L"package.popcap_rsb.extract_resource",
					.argument = LR"({})",
				},
			},
			.separator = {
				2,
				1,
			},
		};

		inline const auto atlas = MethodInvokeCommandConfigGroup{
			.name = L"Atlas",
			.child = {
				{
					.name = L"打包",
					.type = false,
					.rule = std::wregex{LR"(.+(\.atlas)(\.json)$)", std::wregex::icase},
					.method = L"image.atlas.pack",
					.argument = LR"({})",
				},
				{
					.name = L"解包",
					.type = false,
					.rule = std::wregex{LR"(.+(\.atlas)(\.json)$)", std::wregex::icase},
					.method = L"image.atlas.unpack",
					.argument = LR"({})",
				},
				{
					.name = L"自动打包",
					.type = true,
					.rule = std::wregex{LR"(.+(\.sprite)$)", std::wregex::icase},
					.method = L"image.atlas.pack_auto",
					.argument = LR"({})",
				},
			},
			.separator = {
				2,
				1,
			},
		};

		inline const auto popcap_texture = MethodInvokeCommandConfigGroup{
			.name = L"PopCap Texture",
			.child = {
				{
					.name = L"编码",
					.type = false,
					.rule = std::wregex{LR"(.+(\.png)$)", std::wregex::icase},
					.method = L"image.popcap_texture.encode",
					.argument = LR"({})",
				},
				{
					.name = L"编码（rgba_8888）",
					.type = false,
					.rule = std::wregex{LR"(.+(\.png)$)", std::wregex::icase},
					.method = L"image.popcap_texture.encode",
					.argument = LR"({ """format""": """rgba_8888""" })",
				},
				{
					.name = L"编码（argb_8888）",
					.type = false,
					.rule = std::wregex{LR"(.+(\.png)$)", std::wregex::icase},
					.method = L"image.popcap_texture.encode",
					.argument = LR"({ """format""": """argb_8888""" })",
				},
				{
					.name = L"编码（rgba_pvrtc4）",
					.type = false,
					.rule = std::wregex{LR"(.+(\.png)$)", std::wregex::icase},
					.method = L"image.popcap_texture.encode",
					.argument = LR"({ """format""": """rgba_pvrtc4""" })",
				},
				{
					.name = L"编码（rgb_etc1_a_8）",
					.type = false,
					.rule = std::wregex{LR"(.+(\.png)$)", std::wregex::icase},
					.method = L"image.popcap_texture.encode",
					.argument = LR"({ """format""": """rgb_etc1_a_8""" })",
				},
				{
					.name = L"编码（rgb_etc1_a_8_index）",
					.type = false,
					.rule = std::wregex{LR"(.+(\.png)$)", std::wregex::icase},
					.method = L"image.popcap_texture.encode",
					.argument = LR"({ """format""": """rgb_etc1_a_8_index""" })",
				},
				{
					.name = L"解码",
					.type = false,
					.rule = std::wregex{LR"(.+(\.ptx)$)", std::wregex::icase},
					.method = L"image.popcap_texture.decode",
					.argument = LR"({})",
				},
				{
					.name = L"解码（rgba_8888）",
					.type = false,
					.rule = std::wregex{LR"(.+(\.ptx)$)", std::wregex::icase},
					.method = L"image.popcap_texture.decode",
					.argument = LR"({ """format""": """rgba_8888""" })",
				},
				{
					.name = L"解码（argb_8888）",
					.type = false,
					.rule = std::wregex{LR"(.+(\.ptx)$)", std::wregex::icase},
					.method = L"image.popcap_texture.decode",
					.argument = LR"({ """format""": """argb_8888""" })",
				},
				{
					.name = L"解码（rgba_pvrtc4）",
					.type = false,
					.rule = std::wregex{LR"(.+(\.ptx)$)", std::wregex::icase},
					.method = L"image.popcap_texture.decode",
					.argument = LR"({ """format""": """rgba_pvrtc4""" })",
				},
				{
					.name = L"解码（rgb_etc1_a_8）",
					.type = false,
					.rule = std::wregex{LR"(.+(\.ptx)$)", std::wregex::icase},
					.method = L"image.popcap_texture.decode",
					.argument = LR"({ """format""": """rgb_etc1_a_8""" })",
				},
				{
					.name = L"解码（rgb_etc1_a_8_index）",
					.type = false,
					.rule = std::wregex{LR"(.+(\.ptx)$)", std::wregex::icase},
					.method = L"image.popcap_texture.decode",
					.argument = LR"({ """format""": """rgb_etc1_a_8_index""" })",
				},
			},
			.separator = {
				6,
				6,
			},
		};

		inline const auto popcap_animation = MethodInvokeCommandConfigGroup{
			.name = L"PopCap Animation",
			.child = {
				{
					.name = L"编码",
					.type = false,
					.rule = std::wregex{LR"(.+(\.pam)(\.json)$)", std::wregex::icase},
					.method = L"animation.popcap_animation.encode",
					.argument = LR"({})",
				},
				{
					.name = L"解码",
					.type = false,
					.rule = std::wregex{LR"(.+(\.pam)$)", std::wregex::icase},
					.method = L"animation.popcap_animation.decode",
					.argument = LR"({})",
				},
				{
					.name = L"JSON转换至Flash",
					.type = false,
					.rule = std::wregex{LR"(.+(\.pam)(\.json)$)", std::wregex::icase},
					.method = L"animation.popcap_animation.convert.flash.from",
					.argument = LR"({})",
				},
				{
					.name = L"JSON转换自Flash",
					.type = true,
					.rule = std::wregex{LR"(.+(\.pam)(\.xfl)$)", std::wregex::icase},
					.method = L"animation.popcap_animation.convert.flash.to",
					.argument = LR"({})",
				},
				{
					.name = L"Flash图像分辨率调整",
					.type = true,
					.rule = std::wregex{LR"(.+(\.pam)(\.xfl)$)", std::wregex::icase},
					.method = L"animation.popcap_animation.convert.flash.resize",
					.argument = LR"({})",
				},
				{
					.name = L"Flash图像分辨率调整（1536）",
					.type = true,
					.rule = std::wregex{LR"(.+(\.pam)(\.xfl)$)", std::wregex::icase},
					.method = L"animation.popcap_animation.convert.flash.resize",
					.argument = LR"({ """resolution""": 1536 })",
				},
				{
					.name = L"Flash图像分辨率调整（768）",
					.type = true,
					.rule = std::wregex{LR"(.+(\.pam)(\.xfl)$)", std::wregex::icase},
					.method = L"animation.popcap_animation.convert.flash.resize",
					.argument = LR"({ """resolution""": 768 })",
				},
				{
					.name = L"Flash创建图像文件链接",
					.type = true,
					.rule = std::wregex{LR"(.+(\.pam)(\.xfl)$)", std::wregex::icase},
					.method = L"animation.popcap_animation.convert.flash.link_media",
					.argument = LR"({})",
				},
				{
					.name = L"[批处理] 编码",
					.type = true,
					.rule = std::nullopt,
					.method = L"animation.popcap_animation.encode.batch",
					.argument = LR"({})",
				},
				{
					.name = L"[批处理] 解码",
					.type = true,
					.rule = std::nullopt,
					.method = L"animation.popcap_animation.decode.batch",
					.argument = LR"({})",
				},
				{
					.name = L"[批处理] JSON转换至Flash",
					.type = true,
					.rule = std::nullopt,
					.method = L"animation.popcap_animation.convert.flash.from.batch",
					.argument = LR"({})",
				},
				{
					.name = L"[批处理] JSON转换自Flash",
					.type = true,
					.rule = std::nullopt,
					.method = L"animation.popcap_animation.convert.flash.to.batch",
					.argument = LR"({})",
				},
				{
					.name = L"[批处理] Flash图像分辨率调整",
					.type = true,
					.rule = std::nullopt,
					.method = L"animation.popcap_animation.convert.flash.resize.batch",
					.argument = LR"({})",
				},
				{
					.name = L"[批处理] Flash图像分辨率调整（1536）",
					.type = true,
					.rule = std::nullopt,
					.method = L"animation.popcap_animation.convert.flash.resize.batch",
					.argument = LR"({ """resolution""": 1536 })",
				},
				{
					.name = L"[批处理] Flash图像分辨率调整（768）",
					.type = true,
					.rule = std::nullopt,
					.method = L"animation.popcap_animation.convert.flash.resize.batch",
					.argument = LR"({ """resolution""": 768 })",
				},
				{
					.name = L"[批处理] Flash创建图像文件链接",
					.type = true,
					.rule = std::nullopt,
					.method = L"animation.popcap_animation.convert.flash.link_media.batch",
					.argument = LR"({})",
				},
			},
			.separator = {
				2,
				2,
				3,
				1,
				2,
				2,
				3,
				1,
			},
		};

		inline const auto wwise_sound_bank = MethodInvokeCommandConfigGroup{
			.name = L"Wwise Sound-Bank",
			.child = {
				{
					.name = L"打包",
					.type = true,
					.rule = std::wregex{LR"(.+(\.bnk)(\.package)$)", std::wregex::icase},
					.method = L"audio.wwise_sound_bank.pack",
					.argument = LR"({})",
				},
				{
					.name = L"解包",
					.type = false,
					.rule = std::wregex{LR"(.+(\.bnk)$)", std::wregex::icase},
					.method = L"audio.wwise_sound_bank.unpack",
					.argument = LR"({})",
				},
				{
					.name = L"[批处理] 打包",
					.type = true,
					.rule = std::nullopt,
					.method = L"audio.wwise_sound_bank.pack.batch",
					.argument = LR"({})",
				},
				{
					.name = L"[批处理] 解包",
					.type = true,
					.rule = std::nullopt,
					.method = L"audio.wwise_sound_bank.unpack.batch",
					.argument = LR"({})",
				},
			},
			.separator = {
				2,
				2,
			},
		};

		inline const auto wwise_encoded_media = MethodInvokeCommandConfigGroup{
			.name = L"Wwise Encoded-Media",
			.child = {
				{
					.name = L"解码",
					.type = false,
					.rule = std::wregex{LR"(.+(\.wem)$)", std::wregex::icase},
					.method = L"audio.wwise_encoded_media.decode",
					.argument = LR"({})",
				},
				{
					.name = L"[批处理] 解码",
					.type = true,
					.rule = std::nullopt,
					.method = L"audio.wwise_encoded_media.decode.batch",
					.argument = LR"({})",
				},
			},
			.separator = {
				1,
				1,
			},
		};

		inline const auto popcap_rton = MethodInvokeCommandConfigGroup{
			.name = L"PopCap RTON",
			.child = {
				{
					.name = L"编码",
					.type = false,
					.rule = std::wregex{LR"(.+(\.json)$)", std::wregex::icase},
					.method = L"other.popcap_rton.encode",
					.argument = LR"({})",
				},
				{
					.name = L"解码",
					.type = false,
					.rule = std::wregex{LR"(.+(\.rton)$)", std::wregex::icase},
					.method = L"other.popcap_rton.decode",
					.argument = LR"({})",
				},
				{
					.name = L"加密",
					.type = false,
					.rule = std::wregex{LR"(.+(\.rton)$)", std::wregex::icase},
					.method = L"other.popcap_rton.encrypt",
					.argument = LR"({})",
				},
				{
					.name = L"解密",
					.type = false,
					.rule = std::wregex{LR"(.+(\.rton)$)", std::wregex::icase},
					.method = L"other.popcap_rton.decrypt",
					.argument = LR"({})",
				},
				{
					.name = L"编码并加密",
					.type = false,
					.rule = std::wregex{LR"(.+(\.json)$)", std::wregex::icase},
					.method = L"other.popcap_rton.encode_then_encrypt",
					.argument = LR"({})",
				},
				{
					.name = L"解密并解码",
					.type = false,
					.rule = std::wregex{LR"(.+(\.rton)$)", std::wregex::icase},
					.method = L"other.popcap_rton.decrypt_then_decode",
					.argument = LR"({})",
				},
				{
					.name = L"[批处理] 编码",
					.type = true,
					.rule = std::nullopt,
					.method = L"other.popcap_rton.encode.batch",
					.argument = LR"({})",
				},
				{
					.name = L"[批处理] 解码",
					.type = true,
					.rule = std::nullopt,
					.method = L"other.popcap_rton.decode.batch",
					.argument = LR"({})",
				},
				{
					.name = L"[批处理] 加密",
					.type = true,
					.rule = std::nullopt,
					.method = L"other.popcap_rton.encrypt.batch",
					.argument = LR"({})",
				},
				{
					.name = L"[批处理] 解密",
					.type = true,
					.rule = std::nullopt,
					.method = L"other.popcap_rton.decrypt.batch",
					.argument = LR"({})",
				},
				{
					.name = L"[批处理] 编码并加密",
					.type = true,
					.rule = std::nullopt,
					.method = L"other.popcap_rton.encode_then_encrypt.batch",
					.argument = LR"({})",
				},
				{
					.name = L"[批处理] 解密并解码",
					.type = true,
					.rule = std::nullopt,
					.method = L"other.popcap_rton.decrypt_then_decode.batch",
					.argument = LR"({})",
				},
			},
			.separator = {
				2,
				2,
				2,
				2,
				2,
				2,
			},
		};

		inline const auto popcap_zlib = MethodInvokeCommandConfigGroup{
			.name = L"PopCap ZLib",
			.child = {
				{
					.name = L"压缩",
					.type = false,
					.rule = std::nullopt,
					.method = L"other.popcap_zlib.compress",
					.argument = LR"({})",
				},
				{
					.name = L"解压",
					.type = false,
					.rule = std::nullopt,
					.method = L"other.popcap_zlib.uncompress",
					.argument = LR"({})",
				},
				{
					.name = L"[批处理] 压缩",
					.type = true,
					.rule = std::nullopt,
					.method = L"other.popcap_zlib.compress.batch",
					.argument = LR"({})",
				},
				{
					.name = L"[批处理] 解压",
					.type = true,
					.rule = std::nullopt,
					.method = L"other.popcap_zlib.uncompress.batch",
					.argument = LR"({})",
				},
			},
			.separator = {
				2,
				2,
			},
		};

		inline const auto pvz2_lawnstring_text = MethodInvokeCommandConfigGroup{
			.name = L"PvZ2 LawnString Text",
			.child = {
				{
					.name = L"转换为 text",
					.type = false,
					.rule = std::wregex{LR"(.*(LawnStrings).*(\.(txt|json))$)", std::wregex::icase},
					.method = L"other.pvz2.lawn_string_text.convert",
					.argument = LR"({ """dest_version""": """text""" })",
				},
				{
					.name = L"转换为 json_map",
					.type = false,
					.rule = std::wregex{LR"(.*(LawnStrings).*(\.(txt|json))$)", std::wregex::icase},
					.method = L"other.pvz2.lawn_string_text.convert",
					.argument = LR"({ """dest_version""": """json_map""" })",
				},
				{
					.name = L"转换为 json_list",
					.type = false,
					.rule = std::wregex{LR"(.*(LawnStrings).*(\.(txt|json))$)", std::wregex::icase},
					.method = L"other.pvz2.lawn_string_text.convert",
					.argument = LR"({ """dest_version""": """json_list""" })",
				},
			},
			.separator = {
				3,
			},
		};

		// ------------------------------------------------

	}

	// ------------------------------------------------

	class __declspec(uuid("A918A8A8-1436-43C5-99C1-9420D0D56D40")) LaunchMethodInvokeCommand : public MethodInvokeCommand {
	public:
		LaunchMethodInvokeCommand ():
			MethodInvokeCommand{MethodInvokeCommandConfigList::launch} {
		}
	};

	class __declspec(uuid("314F8A42-AC6F-4192-8F9A-D2DF1C9F0546")) JSEvaluateMethodInvokeCommand : public MethodInvokeCommand {
	public:
		JSEvaluateMethodInvokeCommand ():
			MethodInvokeCommand{MethodInvokeCommandConfigList::js_evaluate} {
		}
	};

	class __declspec(uuid("D60FB9DD-7677-4742-A2BC-C9049E268CBA")) JSONMethodInvokeGroupCommand : public MethodInvokeGroupCommand {
	public:
		JSONMethodInvokeGroupCommand ():
			MethodInvokeGroupCommand{MethodInvokeCommandConfigList::json} {
		}
	};

	class __declspec(uuid("1DAED04B-CD51-45DA-91E4-F15DC831C7D5")) DataMethodInvokeGroupCommand : public MethodInvokeGroupCommand {
	public:
		DataMethodInvokeGroupCommand ():
			MethodInvokeGroupCommand{MethodInvokeCommandConfigList::data} {
		}
	};

	class __declspec(uuid("64DBC2C3-402F-42AA-B8BF-B43B3280F813")) PopCapPAKMethodInvokeGroupCommand : public MethodInvokeGroupCommand {
	public:
		PopCapPAKMethodInvokeGroupCommand ():
			MethodInvokeGroupCommand{MethodInvokeCommandConfigList::popcap_pak} {
		}
	};

	class __declspec(uuid("164D100A-5228-429D-A926-EFF742D00E9D")) PopCapDZMethodInvokeGroupCommand : public MethodInvokeGroupCommand {
	public:
		PopCapDZMethodInvokeGroupCommand ():
			MethodInvokeGroupCommand{MethodInvokeCommandConfigList::popcap_dz} {
		}
	};

	class __declspec(uuid("95E74A50-81DC-48BA-A24B-E0AD30C75139")) PopCapRSGPMethodInvokeGroupCommand : public MethodInvokeGroupCommand {
	public:
		PopCapRSGPMethodInvokeGroupCommand ():
			MethodInvokeGroupCommand{MethodInvokeCommandConfigList::popcap_rsgp} {
		}
	};

	class __declspec(uuid("BCF8438E-67D1-4B7B-8649-78C46FAB4CFE")) PopCapRSBMethodInvokeGroupCommand : public MethodInvokeGroupCommand {
	public:
		PopCapRSBMethodInvokeGroupCommand ():
			MethodInvokeGroupCommand{MethodInvokeCommandConfigList::popcap_rsb} {
		}
	};

	class __declspec(uuid("2BEEB70E-8211-4DB4-B6BF-8D6FDAB791BF")) AtlasMethodInvokeGroupCommand : public MethodInvokeGroupCommand {
	public:
		AtlasMethodInvokeGroupCommand ():
			MethodInvokeGroupCommand{MethodInvokeCommandConfigList::atlas} {
		}
	};

	class __declspec(uuid("654DB9CD-DA07-4942-96A5-57F948C6A44C")) PopCapTextureMethodInvokeGroupCommand : public MethodInvokeGroupCommand {
	public:
		PopCapTextureMethodInvokeGroupCommand ():
			MethodInvokeGroupCommand{MethodInvokeCommandConfigList::popcap_texture} {
		}
	};

	class __declspec(uuid("D3EBD69C-CB8B-452D-BFC7-7C06519BDA68")) PopCapAnimationMethodInvokeGroupCommand : public MethodInvokeGroupCommand {
	public:
		PopCapAnimationMethodInvokeGroupCommand ():
			MethodInvokeGroupCommand{MethodInvokeCommandConfigList::popcap_animation} {
		}
	};

	class __declspec(uuid("8B32AE59-795E-4F2D-B3B8-A4558CF9488F")) WwiseSoundBankMethodInvokeGroupCommand : public MethodInvokeGroupCommand {
	public:
		WwiseSoundBankMethodInvokeGroupCommand ():
			MethodInvokeGroupCommand{MethodInvokeCommandConfigList::wwise_sound_bank} {
		}
	};

	class __declspec(uuid("C9A257AC-8048-4257-85AD-CE68CACD7922")) WwiseEncodedMediaMethodInvokeGroupCommand : public MethodInvokeGroupCommand {
	public:
		WwiseEncodedMediaMethodInvokeGroupCommand ():
			MethodInvokeGroupCommand{MethodInvokeCommandConfigList::wwise_encoded_media} {
		}
	};

	class __declspec(uuid("A7121460-0260-4E4A-829F-D21A7E649B50")) PopCapRTONMethodInvokeGroupCommand : public MethodInvokeGroupCommand {
	public:
		PopCapRTONMethodInvokeGroupCommand ():
			MethodInvokeGroupCommand{MethodInvokeCommandConfigList::popcap_rton} {
		}
	};

	class __declspec(uuid("5F334CE4-29A4-4B0F-A696-10EB3D773666")) PopCapZLibMethodInvokeGroupCommand : public MethodInvokeGroupCommand {
	public:
		PopCapZLibMethodInvokeGroupCommand ():
			MethodInvokeGroupCommand{MethodInvokeCommandConfigList::popcap_zlib} {
		}
	};

	class __declspec(uuid("3F961602-866A-4305-8031-42597990C6AB")) PvZ2LawnStringTextMethodInvokeGroupCommand : public MethodInvokeGroupCommand {
	public:
		PvZ2LawnStringTextMethodInvokeGroupCommand ():
			MethodInvokeGroupCommand{MethodInvokeCommandConfigList::pvz2_lawnstring_text} {
		}
	};

	// ------------------------------------------------

}

// ------------------------------------------------
