// MiraiCP依赖文件(只需要引入这一个)
#include <MiraiCP.hpp>
using namespace MiraiCP;
using std::string;
// 插件实例
class Main : public CPPPlugin {
public:
	// 配置插件信息
	Main() : CPPPlugin(PluginConfig("work_hcat_CPPGroupHelpBot", "CPPGroupHelpBot", "V1.0", "Hcat", "", "Publish time")) {}

	void onEnable() override {
		Event::registerEvent<GroupMessageEvent>([](GroupMessageEvent e) {

			if (e.group.id() == 951028656 && (e.sender.id() != e.group.botid())) {
				string msg = e.message.source.value().serializeToString();
				//查找消息中是否包含C4996
				if (msg.find("C4996") != string::npos || msg.find("C4999") != string::npos || msg.find("CRT_SECURE") != string::npos) {
					e.group.quoteAndSendMessage(PlainText("FAQ 自助问题解答"), e.message.source.value());
					e.group.sendMessage("方法一：请在报错文件第一行添加代码： #define _CRT_SECURE_NO_DEPRECATE   和  _CRT_SECURE_NO_WARNINGS ");
					e.group.sendMessage("方法二：右键项目=>属性=>配置属性=> C/C++ =>SDL检查，将其更改为否。");
				}


			}
			});
	}

	void onDisable() override {	}

};
// 绑定当前插件实例
void MiraiCP::enrollPlugin() {
	MiraiCP::enrollPlugin0(new Main());
};