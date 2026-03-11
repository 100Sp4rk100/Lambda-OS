#include "script_template.h"

namespace Code {

constexpr ScriptTemplate emptyScriptTemplate(".py", R"()");

constexpr ScriptTemplate getTimeTemplate("getTime.py",
                                               R"(from time import *
print(getTime()))");

constexpr ScriptTemplate setTimeTemplate(
    "setTime.py", R"(from time import *
h = int(input("Hours: "))
m = int(input("Minutes: "))
s = int(input("Seconds: "))
setTime(h, m, s)
)");

constexpr ScriptTemplate resetTimeTemplate(
    "resetTime.py", R"(from time import *
resetTime()
)");

const ScriptTemplate* ScriptTemplate::Empty() { return &emptyScriptTemplate; }

const ScriptTemplate* ScriptTemplate::Get() { return &getTimeTemplate; }
const ScriptTemplate* ScriptTemplate::Set() { return &setTimeTemplate; }
const ScriptTemplate* ScriptTemplate::Reset() { return &resetTimeTemplate; }

}  // namespace Code
