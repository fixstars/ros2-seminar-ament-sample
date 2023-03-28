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

#pragma once

#include <pluginlib/class_loader.hpp>
#include <rclcpp/rclcpp.hpp>
#include <simple_plugin_base/simple_plugin_base.hpp>

class SimplePluginNode : public rclcpp::Node
{
public:
  SimplePluginNode()
  : Node("simple_node")
  {
    pluginlib::ClassLoader<simple_plugin::SimplePluginBase> simple_plugin_loader(
      /* プラグインベースパッケージ */ "simple_plugin_base",
      /* プラグインベースクラス*/ "simple_plugin::SimplePluginBase");

    try {
      auto simple_plugin = simple_plugin_loader.createSharedInstance(
        /* プラグイン名 */ "simple_plugin/SimplePlugin");
      simple_plugin->Print();
    } catch (pluginlib::PluginlibException & ex) {
      printf("Load error: %s\n", ex.what());
    }
  }
};
