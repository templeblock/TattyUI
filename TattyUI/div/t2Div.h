﻿#ifndef T2_DIV_H
#define T2_DIV_H

#include <TattyUI/common/t2Vector2.h>
#include <TattyUI/div/t2Style.h>
#include <functional>

namespace TattyUI
{
    enum t2DivStatus
    {
        T2_NORMAL,
        T2_HOVER,
        T2_ACTIVE
    };

    class t2Div
    {
    public:
        // --!fontName fontPath可以缺省直接由css提供
        t2Div();
        // 由宿主语言直接创建div
        t2Div(int width, int height, string fontName, string fontPath);

        // --!一定要在css内容都已经完成赋值后才可调用
        // 初始化具体div属性默认内容，包括内外边距阴影初始化
        void init();

        //void update();

        void draw();

        void setStatus(int status);

        int getStatus();

        // 获取当前状态的样式表
        t2Style& getCSS();

        // 给定位置是否在div内部
        bool inDiv(int x, int y);

        bool inDiv(t2Point2i p);

        // 给定位置是否在div所有子节点内部
        bool inChild(int x, int y);
        
        bool inChild(t2Point2i pos);

        // 类型名
        string className;

        t2Style normal, active, hover;

        // 依附于三种基本状态存在的条件状态
        //t2Style condition;

        // 父节点 / 兄弟节点 / 第一个孩子节点
        t2Div* parent, *next, *child;

        // --!测试使用
        // 是否渲染padding margin包围盒
        bool bDrawPaddingAABB, bDrawMarginAABB;

        // 回调 所有callback都指定为这此
         std::function<void(int x, int y, int px, int py, int button)> mousePressed;

         std::function<void(int x, int y, int px, int py, int button)> mouseReleased;

         std::function<void(int x, int y, int px, int py)> mouseMoved;

         // 鼠标移入移出回调
         std::function<void(int x, int y, int px, int py)> mouseMovedIn;

         std::function<void(int x, int y, int px, int py)> mouseMovedOut;

         std::function<void(int x, int y, int px, int py)> mouseScrolled;

         std::function<void(int key)> keyPressed;

         std::function<void(int key)> keyReleased;
    private:
        // 根据兄弟结点 父节点位置更新自身实际渲染位置
        //void updateContent();

        virtual void onMousePressed(int x, int y, int px, int py, int button);

        virtual void onMouseReleased(int x, int y, int px, int py, int button);

        virtual void onMouseMoved(int x, int y, int px, int py);

        virtual void onMouseScrolled(int x, int y, int px, int py);

        virtual void onKeyPressed(int key);

        virtual void onKeyReleased(int key);

        friend class t2DivController;

        friend class t2CSSController;

        friend class t2LayoutController;

        int status;

        // 是否有被赋值
        bool bNormal, bActive, bHover;
        //bool bCondition;

        // 布局方式
        int layout;
    };
}

#endif