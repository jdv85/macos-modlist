#include <cstdio>
#include <IOKit/kext/KextManager.h>

CFStringRef bundleExePath = CFStringCreateWithCString(kCFAllocatorDefault, "OSBundleExecutablePath", kCFStringEncodingASCII);

void enumItems(const void* key, const void* value, void* context) {
    CFStringRef keyStr = (CFStringRef) key;
    const char* keyString = CFStringGetCStringPtr(keyStr, kCFStringEncodingUTF8);

    CFDictionaryRef valueDict = (CFDictionaryRef) value;
    CFStringRef path = (CFStringRef) CFDictionaryGetValue(valueDict, bundleExePath);
    const char* pathString = "n/a";
    if(path) {
        pathString = CFStringGetCStringPtr(path, kCFStringEncodingUTF8);
    }


    printf("%s: %s\n", keyString, pathString);
}

int main() {
    CFDictionaryRef kextInfo = KextManagerCopyLoadedKextInfo(nullptr, nullptr);
    CFDictionaryApplyFunction(kextInfo, enumItems, nullptr);
    return 0;
}