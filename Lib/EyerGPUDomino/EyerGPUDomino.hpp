#ifndef EYE_LIB_EYERGPUDOMINO_H
#define EYE_LIB_EYERGPUDOMINO_H

#include "EyerCore/EyerCore.hpp"
#include "EyerGL/EyerGL.hpp"

namespace Eyer
{
    class EyerGomino;
    class EyerGominoPip;
    class EyerGominoGaussianBlur;
    class EyerGaussianBlurComponent;
    class EyerGominoCopy;

    class EyerGomino
    {
    public:
        EyerGomino(EyerString name);
        EyerGomino(EyerGomino & gomino);
        virtual ~EyerGomino();

        EyerGomino & operator = (EyerGomino & gomino);

        int ClearAll();

        EyerString name;

        virtual int Go(EyerGLTexture * input, EyerGLTexture * output, int width, int height) = 0;

    private:

    };

    class EyerGominoPip {
    public:
        EyerGominoPip();
        ~EyerGominoPip();

        int operator << (EyerGomino * gomino);

        int ClearAll();

        int PrintStruct();

        int Go(EyerGLTexture * input, EyerGLTexture * output, int width, int height);

    private:
        EyerLinkedList<EyerGomino *> gomineList;
    };


    class EyerGominoGaussianBlur : public EyerGomino
    {
    public:
        EyerGominoGaussianBlur();
        ~EyerGominoGaussianBlur();

        virtual int Go(EyerGLTexture * input, EyerGLTexture * output, int width, int height);
    };

    class EyerGominoCopy: public EyerGomino
    {
    public:
        EyerGominoCopy();
        ~EyerGominoCopy();

        virtual int Go(EyerGLTexture * input, EyerGLTexture * output, int width, int height);
    };

    class EyerGaussianBlurComponent : public EyerGLComponent
    {
    public:
        EyerGaussianBlurComponent();
        ~EyerGaussianBlurComponent();

        virtual int Draw();

        int SetTexture(EyerGLTexture * _texture);

        int SetWH(int _w, int _h);

    private:
        EyerGLDraw * draw = nullptr;
        EyerGLVAO * vao = nullptr;
        EyerGLTexture * texture = nullptr;

        int w = 1920;
        int h = 1080;
    };



    class EyerCopyTextureComponent : public EyerGLComponent
    {
    public:
        EyerCopyTextureComponent();
        ~EyerCopyTextureComponent();

        virtual int Draw();

        int SetTexture(EyerGLTexture * _texture);

        int SetWH(int _w, int _h);

    private:
        EyerGLDraw * draw = nullptr;
        EyerGLVAO * vao = nullptr;
        EyerGLTexture * texture = nullptr;

        int w = 1920;
        int h = 1080;
    };

}

#endif //EYE_LIB_EYERGPUDOMINO_H