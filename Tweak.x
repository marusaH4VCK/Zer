// Tweak.x — inject GameMenuUI into target app
// แก้ BUNDLE_ID ในไฟล์ control ให้ตรงกับ app ที่ต้องการ inject

#import "src/GameMenuUI.h"

// เปิดเมนูด้วยการ triple-tap บนหน้าจอ
%hook UIApplication

- (void)sendEvent:(UIEvent *)event {
    %orig;

    static NSUInteger tapCount = 0;
    static NSTimeInterval lastTap = 0;

    UITouch *touch = [event.allTouches anyObject];
    if (!touch) return;

    if (touch.phase == UITouchPhaseEnded && touch.tapCount == 3) {
        NSTimeInterval now = [NSDate date].timeIntervalSince1970;
        if (now - lastTap < 0.5) tapCount++;
        else tapCount = 1;
        lastTap = now;

        if (tapCount >= 1) {
            tapCount = 0;
            dispatch_async(dispatch_get_main_queue(), ^{
                GMMenuWindow *w = [GMMenuWindow sharedWindow];
                if (w.hidden) [w show]; else [w hide];
            });
        }
    }
}

%end
