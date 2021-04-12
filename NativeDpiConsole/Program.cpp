#define WIN32_LEAN_AND_MEAN

#include <iostream>
#include <windows.h>

#define VAR_NAME(x) (#x)

void DebugDpiAwareness(DPI_AWARENESS_CONTEXT dpiContext, const char *dpiContextName, const char *expectedAwarenessName)
{
    DPI_AWARENESS_CONTEXT prev0 = SetThreadDpiAwarenessContext(dpiContext);
    DPI_AWARENESS_CONTEXT currentContext = GetThreadDpiAwarenessContext();
    DPI_AWARENESS actualAwareness = GetAwarenessFromDpiAwarenessContext(currentContext);

    std::cout << "DPI Context: " << dpiContextName << ", expected " << expectedAwarenessName << ", actual awareness (" << (int)actualAwareness << ")\n";
}

int main()
{
    DebugDpiAwareness(DPI_AWARENESS_CONTEXT_UNAWARE, VAR_NAME(DPI_AWARENESS_CONTEXT_UNAWARE), "UNAWARE");
    DebugDpiAwareness(DPI_AWARENESS_CONTEXT_SYSTEM_AWARE, VAR_NAME(DPI_AWARENESS_CONTEXT_SYSTEM_AWARE), "SYSTEM_AWARE");
    DebugDpiAwareness(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE, VAR_NAME(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE), "PER_MONITOR_AWARE");
    DebugDpiAwareness(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2, VAR_NAME(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2), "PER_MONITOR_AWARE");

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
