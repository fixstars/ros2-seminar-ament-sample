/*
Copyright 2023 Fixstars Corporation

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the “Software”), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <iostream>
#include <simple_plugin_base/simple_plugin_base.hpp>

namespace simple_plugin
{
class SimplePlugin : public SimplePluginBase
{
public:
  virtual void Print() override
  {
    std::cout << "inside SimplePlugin" << std::endl;
  }
};
}  // namespace simple_plugin

// PLUGINLIB_EXPORT_CLASS でクラスローダへの登録を行う
#include <pluginlib/class_list_macros.hpp>
PLUGINLIB_EXPORT_CLASS(
  simple_plugin::SimplePlugin,
  simple_plugin::SimplePluginBase)
