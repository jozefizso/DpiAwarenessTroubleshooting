# DPI Awareness Troubleshooting

> Calling DPI awareness Win32 methods from .NET causes incorrect values
> to be set or reported.


## `DPI_AWARENESS` enum (windef.h)

```cpp
typedef enum DPI_AWARENESS {
    DPI_AWARENESS_INVALID           = -1,
    DPI_AWARENESS_UNAWARE           = 0,
    DPI_AWARENESS_SYSTEM_AWARE      = 1,
    DPI_AWARENESS_PER_MONITOR_AWARE = 2
} DPI_AWARENESS;
```

Equivalent enum defined in our code:

```csharp
public enum DPI_AWARENESS
{
	INVALID = 0,
	UNAWARE = 1,
	SYSTEM_AWARE = 2,
	PER_MONITOR_AWARE = 3
}
```


## Getting Started

Run the *NetDpiApp* Win Forms application and observe the output from
the `DebugDpi2()` method.

The method will set thread DPI awareness context and read the current
awareness value from current thread.
The values set by `DPI_AWARENESS_CONTEXT` handle are not converted correctly
back to `DPI_AWARENESS` enum - all values are one level lower then actual thread
awarennes.

This issue does not happen in the C++ app *NativeDpiConsole*.

```
DPI Context: DPI_AWARENESS_CONTEXT_UNAWARE              (-1 / 0xFFFFFFFF), expecting UNAWARE          , actual awareness INVALID (0)
DPI Context: DPI_AWARENESS_CONTEXT_SYSTEM_AWARE         (-2 / 0xFFFFFFFE), expecting SYSTEM_AWARE     , actual awareness UNAWARE (1)
DPI Context: DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE    (-3 / 0xFFFFFFFD), expecting PER_MONITOR_AWARE, actual awareness SYSTEM_AWARE (2)
DPI Context: DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2 (-4 / 0xFFFFFFFC), expecting PER_MONITOR_AWARE, actual awareness SYSTEM_AWARE (2)
```
