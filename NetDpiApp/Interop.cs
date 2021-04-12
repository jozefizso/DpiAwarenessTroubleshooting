using System;
using System.Runtime.InteropServices;

namespace NetDpiApp
{
    public class Interop
    {
        public static readonly IntPtr UNAWARE = new IntPtr(-1);
        public static readonly IntPtr SYSTEM_AWARE = new IntPtr(-2);
        public static readonly IntPtr PER_MONITOR_AWARE = new IntPtr(-3);
        public static readonly IntPtr PER_MONITOR_AWARE_V2 = new IntPtr(-4);
        public static readonly IntPtr UNAWARE_GDISCALED = new IntPtr(-5);

        [DllImport("user32.dll")]
        public static extern IntPtr GetThreadDpiAwarenessContext();

        [DllImport("user32.dll")]
        public static extern DPI_AWARENESS GetAwarenessFromDpiAwarenessContext(IntPtr context);

        [DllImport("user32.dll")]
        public static extern IntPtr SetThreadDpiAwarenessContext(IntPtr dpiContext);
    }

    public enum DPI_AWARENESS
    {
        INVALID = 0,
        UNAWARE = 1,
        SYSTEM_AWARE = 2,
        PER_MONITOR_AWARE = 3
    }
}
