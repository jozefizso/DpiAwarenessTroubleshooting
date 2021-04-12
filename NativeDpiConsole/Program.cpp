#define WIN32_LEAN_AND_MEAN

#include <iostream>
#include <windows.h>

int main()
{
    DPI_AWARENESS_CONTEXT unaware = DPI_AWARENESS_CONTEXT_UNAWARE;
    DPI_AWARENESS_CONTEXT system = DPI_AWARENESS_CONTEXT_SYSTEM_AWARE;
    DPI_AWARENESS_CONTEXT perMonitor = DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE;
    DPI_AWARENESS_CONTEXT perMonitorV2 = DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2;


    DPI_AWARENESS_CONTEXT ctx0 = GetThreadDpiAwarenessContext();
    DPI_AWARENESS a0 = GetAwarenessFromDpiAwarenessContext(ctx0);

    DPI_AWARENESS_CONTEXT p1 = SetThreadDpiAwarenessContext(perMonitorV2);
    DPI_AWARENESS_CONTEXT ctx1 = GetThreadDpiAwarenessContext();
    DPI_AWARENESS ap1 = GetAwarenessFromDpiAwarenessContext(p1);
    DPI_AWARENESS a1 = GetAwarenessFromDpiAwarenessContext(ctx1);

    DPI_AWARENESS_CONTEXT p2 = SetThreadDpiAwarenessContext(DPI_AWARENESS_CONTEXT_SYSTEM_AWARE);
    DPI_AWARENESS_CONTEXT ctx2 = GetThreadDpiAwarenessContext();
    DPI_AWARENESS ap2 = GetAwarenessFromDpiAwarenessContext(p2);
    DPI_AWARENESS a2 = GetAwarenessFromDpiAwarenessContext(ctx2);

    DPI_AWARENESS_CONTEXT ctxX = SetThreadDpiAwarenessContext(p1);
    DPI_AWARENESS aX = GetAwarenessFromDpiAwarenessContext(ctxX);

    std::cout << "Hello World!\n";
}
