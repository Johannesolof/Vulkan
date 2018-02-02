#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>
#include "helper.h"
#include "Vertex.h"

#define DEBUG

class Application {

public:
	Application();
	~Application();

	void run();
	

private:

	static void onWindowResized(GLFWwindow* window, int width, int height);
	void initWindow();
	std::vector<const char*> getRequiredExtensions();
	bool checkVadlidationLayerSupport();
	void createInstance();
	void setupDebugCallback();
	helper::QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
	bool checkExtensionSupport(VkPhysicalDevice device);
	helper::SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
	int deviceScore(VkPhysicalDevice device);
	void pickPhysicalDevice();
	void createLogicalDevice();
	void createSurface();
	VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<struct VkSurfaceFormatKHR>& formats);
	VkPresentModeKHR chooseSwapPresentMode(const std::vector<enum VkPresentModeKHR>& presentModes);
	VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
	void createSwapChain();
	VkImageView createImageView(VkImage image, VkFormat format);
	void createImageViews();
	VkShaderModule createShaderModule(const std::vector<char>& shaderCode);
	void createRenderPass();
	void createDescriptorSetLayout();
	void createGraphicsPipeline();
	void createFrameBuffers();
	void createCommandPool();
	uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);
	void createBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer,
	                  VkDeviceMemory& bufferMemory);
	VkCommandBuffer beginSingleTimeCommands();
	void endSingleTimeCommands(VkCommandBuffer &commandBuffer);
	void copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize bufferSize);
	void createVertexBuffer();
	void createIndexBuffer();
	void createCommandBuffers();
	void createSemaphores();
	void createUniformBuffer();
	void createDescriptorPool();
	void createDescriptorSet();
	void initVulkan();
	void cleanupSwapChain();
	void recreateSwapChain();
	void drawFrame();
	void updateUniformBuffer();
	void mainLoop();
	void cleanup();


	GLFWwindow* _window;
	uint32_t _width;
	uint32_t _height;

	VkInstance _instance;
	VkDebugReportCallbackEXT _callback;

	VkSurfaceKHR _surface;
	VkPhysicalDevice _physicalDevice = VK_NULL_HANDLE;
	VkDevice _device;

	VkQueue _graphicsQueue;
	VkQueue _presentQueue;

	VkSwapchainKHR _swapChain;
	std::vector<VkImage> _swapChainImages;
	VkFormat _swapChainImageFormat;
	VkExtent2D _swapChainExtent;
	std::vector<VkImageView> _swapChainImageViews;
	std::vector<VkFramebuffer> _swapChainFramebuffers;

	VkRenderPass _renderPass;
	VkDescriptorSetLayout _descriptorSetLayout;
	VkPipelineLayout _pipelineLayout;
	VkPipeline _graphicsPipeline;

	VkBuffer _vertexBuffer;
	VkDeviceMemory _vertexBufferMemory;
    VkBuffer _indexBuffer;
    VkDeviceMemory _indexBufferMemory;
	VkBuffer _uniformBuffer;
	VkDeviceMemory _uniformBufferMemory;

	VkDescriptorPool _descriptorPool;
	VkDescriptorSet _descriptorSet;

	VkCommandPool _commandPool;
	std::vector<VkCommandBuffer> _commandBuffers;

	VkSemaphore _imageAvailableSemaphore;
	VkSemaphore _renderFinishedSemaphore;

	const std::vector<const char*> _validationLayers = {
		"VK_LAYER_LUNARG_standard_validation"
	};

	const std::vector<const char*> _deviceExtensions = {
		VK_KHR_SWAPCHAIN_EXTENSION_NAME
	};

#ifdef NDEBUG
	const bool _enableValidationLayers = false;
#else
	const bool _enableValidationLayers = true;
#endif

	const std::vector<Vertex> _vertices = {
		{ { -0.5f, -0.5f },{ 1.0f, 0.0f, 0.0f } },
	{ { 0.5f, -0.5f },{ 0.0f, 1.0f, 0.0f } },
	{ { 0.5f, 0.5f },{ 0.0f, 0.0f, 1.0f } },
	{ { -0.5f, 0.5f },{ 1.0f, 1.0f, 1.0f } }
	};



	const std::vector<uint16_t> _indices = {
		0, 1, 2, 2, 3, 0
	};

	struct UniformBufferObject {
		glm::mat4 model;
		glm::mat4 view;
		glm::mat4 proj;
		glm::mat4 modelViewProj = proj * view * proj;
	};

};

