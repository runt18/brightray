// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Copyright (c) 2013 Patrick Reynolds <piki@github.com>. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE-CHROMIUM file.

#ifndef BRIGHTRAY_BROWSER_NOTIFICATION_PRESENTER_LINUX_H_
#define BRIGHTRAY_BROWSER_NOTIFICATION_PRESENTER_LINUX_H_

#include "base/compiler_specific.h"
#include "browser/notification_presenter.h"

#include <libnotify/notify.h>

#include <map>

namespace brightray {

class NotificationPresenterLinux : public NotificationPresenter {
 public:
  NotificationPresenterLinux();
  ~NotificationPresenterLinux();

  virtual void ShowNotification(
      const content::ShowDesktopNotificationHostMsgParams&,
      int render_process_id,
      int render_view_id) OVERRIDE;
  virtual void CancelNotification(
      int render_process_id,
      int render_view_id,
      int notification_id) OVERRIDE;

  void RemoveNotification(NotifyNotification *former_notification);

 private:
  GList *notifications_;
};

}  // namespace brightray

#endif
