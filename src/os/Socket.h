// Ekam Build System
// Author: Kenton Varda (kenton@sandstorm.io)
// Copyright (c) 2010-2015 Kenton Varda, Google Inc., and contributors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef KENTONSCODE_OS_SOCKET_H_
#define KENTONSCODE_OS_SOCKET_H_

#include "base/OwnedPtr.h"
#include "OsHandle.h"
#include "ByteStream.h"
#include "EventManager.h"

namespace ekam {

class ServerSocket {
public:
  ServerSocket(EventManager* eventManager, const std::string& bindAddress, int backlog = 0);
  ~ServerSocket();

  Promise<OwnedPtr<ByteStream>> accept();

private:
  class AcceptOp;

  EventManager* eventManager;
  OsHandle handle;
  OwnedPtr<EventManager::IoWatcher> watcher;
};

}  // namespace ekam

#endif  // KENTONSCODE_OS_SOCKET_H_
