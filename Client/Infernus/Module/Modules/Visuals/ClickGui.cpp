#include "ClickGui.h"

#include "../../../Category/Category.h"
#include "../../../Manager/Manager.h"

auto ClickGui::onRender(void) -> void {

    auto mgr = this->category->manager;

    if (ImGui::Begin(this->name.c_str())) {

        for (auto category : mgr->categories) {

            if (ImGui::BeginMenu(category->name.c_str())) {

                for (auto mod : category->modules) {

                    if (ImGui::BeginMenu(mod->name.c_str())) {

                        if (ImGui::MenuItem(mod->isEnabled ? "Disable" : "Enable")) {

                            mod->isEnabled = !mod->isEnabled;

                        };

                        if (ImGui::BeginMenu("Options")) {

                            mod->onRenderOptions();
                            if (ImGui::MenuItem(mod->key != NULL ? "Click to bind again" : "Click to bind")) {
                                mod->newKey = true;
                            };
                            ImGui::EndMenu();

                        };

                        ImGui::EndMenu();

                    };

                };

                ImGui::EndMenu();

            };

        };

        ImGui::End();

    };

};