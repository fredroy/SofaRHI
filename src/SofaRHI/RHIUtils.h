#pragma once

#include <SofaRHI/config.h>

#include <QtGui/private/qrhi_p.h>
#include <array>

namespace sofa::rhi::utils
{
    enum class MaterialFlags : int
    {
        NONE = 0,
        USE_PHONG = 1 << 0,
        USE_DIFFUSE_TEXTURE = 1 << 1,
        USE_BUMP_TEXTURE = 1 << 2,
        UNUSED_1 = 1 << 3
        //etc
    };

    //as defined in the shader files
    struct Material
    {
        std::array<float, 4> ambient;
        std::array<float, 4> diffuse;
        std::array<float, 4> specular;
        std::array<float, 4> shininess;// 3 padding of float;
        MaterialFlags flags;
    };

    struct GroupInfo
    {
        uint8_t materialID;
    };

    //Definitions
    constexpr std::size_t MATRIX4_SIZE{ 64 };
    constexpr std::size_t VEC3_SIZE{ 12 };
    constexpr std::size_t MATERIAL_SIZE = sizeof(Material);
    constexpr std::size_t MAXIMUM_MATERIAL_NUMBER{ 9 }; //
    constexpr std::size_t GROUPINFO_SIZE = sizeof(GroupInfo);

    //Helper functions
    QShader loadShader(const std::string& name);

} // namespace sofa::rhi::utils

