using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static NetDpiApp.Interop;

namespace NetDpiApp
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            DebugDpi2();
        }

        private void DebugDpi1()
        {
            var ctx0 = GetThreadDpiAwarenessContext();
            var dpi0 = GetAwarenessFromDpiAwarenessContext(ctx0);

            var prev0 = SetThreadDpiAwarenessContext(PER_MONITOR_AWARE);
            var ctx1 = GetThreadDpiAwarenessContext();
            var dpi1 = GetAwarenessFromDpiAwarenessContext(ctx1);

            var prev1 = SetThreadDpiAwarenessContext(SYSTEM_AWARE);
            var ctx2 = GetThreadDpiAwarenessContext();
            var dpi2 = GetAwarenessFromDpiAwarenessContext(ctx2);

            SetThreadDpiAwarenessContext(prev0);
            var ctxX = GetThreadDpiAwarenessContext();
            var dpiX = GetAwarenessFromDpiAwarenessContext(ctxX);


            Trace.WriteLine($"DPI 0: {dpi0}");
            Trace.WriteLine($"DPI 1: {dpi1}");
            Trace.WriteLine($"DPI 2: {dpi2}");
            Trace.WriteLine($"DPI X: {dpiX}");
        }

        private void DebugDpi2()
        {
            DebugDpiAwareness(UNAWARE, "DPI_AWARENESS_CONTEXT_UNAWARE", "UNAWARE");
            DebugDpiAwareness(SYSTEM_AWARE, "DPI_AWARENESS_CONTEXT_SYSTEM_AWARE", "SYSTEM_AWARE");
            DebugDpiAwareness(PER_MONITOR_AWARE, "DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE", "PER_MONITOR_AWARE");
            DebugDpiAwareness(PER_MONITOR_AWARE_V2, "DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2", "PER_MONITOR_AWARE");
        }

        private void DebugDpiAwareness(IntPtr dpiContext, string dpiContextName, string expectedAwareness)
        {
            var prev0 = SetThreadDpiAwarenessContext(dpiContext);
            var ctx1 = GetThreadDpiAwarenessContext();
            var actualAwareness = GetAwarenessFromDpiAwarenessContext(ctx1);

            var ptrHex = dpiContext.ToInt32().ToString("X");
            var ptrValue = dpiContext.ToInt32().ToString("G");
            var actualAwarenessValue = (int)actualAwareness;


            Trace.WriteLine($"DPI Context: {dpiContextName,-42} ({ptrValue} / 0x{ptrHex}), expecting {expectedAwareness,-17}, actual awareness {actualAwareness} ({actualAwarenessValue})");
        }
    }
}
