#pragma once
#include "../common.hpp"

namespace Spyral
{
    class GUI final
    {
    private:
        GUI();

    public:
        ~GUI();

        GUI(const GUI&) = delete;
		GUI(GUI&&) noexcept = delete;
		GUI& operator=(const GUI&) = delete;
		GUI& operator=(GUI&&) noexcept = delete;

        static void Init()
        { GetInstance(); }

        static bool IsOpen()
        { return GetInstance().m_IsOpen; }

    private:
        void WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

        static GUI& GetInstance()
        {
            static GUI i{};

            return i;
        }

    private:
        bool m_IsOpen;

    };
}