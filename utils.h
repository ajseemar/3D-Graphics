#pragma once

#include <fstream>

// this function loads a file into an Array^
static Platform::Array<unsigned char>^ LoadShaderFile(std::string File)
{
    Platform::Array<unsigned char>^ FileData = nullptr;

    // open the file
    std::ifstream VertexFile(File, std::ios::in | std::ios::binary | std::ios::ate);

    // if open was successful
    if (VertexFile.is_open())
    {
        // find the length of the file
        int Length = (int)VertexFile.tellg();

        // collect the file data
        FileData = ref new Platform::Array<unsigned char>(Length);
        VertexFile.seekg(0, std::ios::beg);
        VertexFile.read(reinterpret_cast<char*>(FileData->Data), Length);
        VertexFile.close();
    }

    return FileData;
}