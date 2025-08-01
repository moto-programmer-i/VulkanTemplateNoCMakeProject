// ���W���[���錾�̑O��include���Ȃ���΃G���[�ɂȂ�
#include <algorithm>

export module VulkanTutorial;

import std;
import Glfw;
import vulkan_hpp;

// Vulkan�̃`���[�g���A��
// https://docs.vulkan.org/tutorial/latest/03_Drawing_a_triangle/00_Setup/00_Base_code.html
export class HelloTriangleApplication {
public:
    // �`���[�g���A���ł�VK_MAKE_VERSION�ō���Ă������A�s�v�Ɍ�����̂Ŏ��O�ŗp�ӁB
    // ���W���[�ԍ� �}�C�i�[�ԍ��i2���j�p�b�`�ԍ��i�Q���j��z��
    static constexpr uint32_t APPLICATION_VERSION = 10000;
    static constexpr uint32_t ENGINE_VERSION = 10000;

    HelloTriangleApplication(Glfw::Window* window) {
        this->window = window;
    }
    void run() {
        std::cout << "vulkan tutorial" << std::endl;

        initVulkan();

        // initVulkan�ȊO��Window���W���[���Ɉڂ������߁A�s�v
        /*initWindow();
        mainLoop();
        cleanup();*/
    }

private:
    // �O���ŊǗ�����Ă���E�B���h�E�B���̃N���X���ł͉�����Ȃ�����
    Glfw::Window *  window;

    vk::raii::Context  context;
    vk::raii::Instance instance = nullptr;

    void initVulkan() {
        createInstance();
    }

    void createInstance() {      
        
        constexpr vk::ApplicationInfo appInfo{.pApplicationName = "Hello Triangle",

            // import vulkan_hpp;���ƂȂ���VK_MAKE_VERSION������`�B
            // �������A�񐄏��̋@�\�̂悤�Ȃ̂ň�U�������āA�Ǝ��ɓK���ɔԍ�������
            // .applicationVersion = VK_MAKE_VERSION(1, 0, 0),
            .applicationVersion = APPLICATION_VERSION,
            
            .pEngineName = "No Engine",
            // .engineVersion = VK_MAKE_VERSION(1, 0, 0),
            .engineVersion = ENGINE_VERSION,
            
            .apiVersion = vk::ApiVersion14 };
        
        

        // Get the required instance extensions from GLFW.
        uint32_t glfwExtensionCount = 0;
        auto glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);


        // Check if the required GLFW extensions are supported by the Vulkan implementation.
        auto extensionProperties = context.enumerateInstanceExtensionProperties();
        for (uint32_t i = 0; i < glfwExtensionCount; ++i)
        {
            if (std::ranges::none_of(extensionProperties,
                [glfwExtension = glfwExtensions[i]](auto const& extensionProperty)
                { return strcmp(extensionProperty.extensionName, glfwExtension) == 0; }))
            
            {
                throw std::runtime_error("Required GLFW extension not supported: " + std::string(glfwExtensions[i]));
            }
        }

        vk::InstanceCreateInfo createInfo{
            .pApplicationInfo = &appInfo,
            .enabledExtensionCount = glfwExtensionCount,
            .ppEnabledExtensionNames = glfwExtensions };
        instance = vk::raii::Instance(context, createInfo);
    }
};
