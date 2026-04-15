#pragma once
#import <UIKit/UIKit.h>

// ─── Colors ─────────────────────────────────────────────────────────────────
#define GM_BG_LIGHT        [UIColor colorWithWhite:0.77f alpha:1.0f]
#define GM_SIDEBAR_LIGHT   [UIColor colorWithWhite:0.73f alpha:1.0f]
#define GM_ROW_LIGHT       [UIColor colorWithWhite:0.60f alpha:1.0f]
#define GM_PILL_LIGHT      [UIColor colorWithWhite:0.67f alpha:1.0f]
#define GM_TEXT_LIGHT      [UIColor colorWithWhite:0.07f alpha:1.0f]
#define GM_SUBTEXT_LIGHT   [UIColor colorWithWhite:0.35f alpha:1.0f]
#define GM_THUMB_LIGHT     [UIColor colorWithWhite:0.94f alpha:1.0f]

#define GM_BG_DARK         [UIColor colorWithWhite:0.23f alpha:1.0f]
#define GM_SIDEBAR_DARK    [UIColor colorWithWhite:0.20f alpha:1.0f]
#define GM_ROW_DARK        [UIColor colorWithWhite:0.29f alpha:1.0f]
#define GM_PILL_DARK       [UIColor colorWithWhite:0.33f alpha:1.0f]
#define GM_TEXT_DARK       [UIColor colorWithWhite:0.93f alpha:1.0f]
#define GM_SUBTEXT_DARK    [UIColor colorWithWhite:0.55f alpha:1.0f]
#define GM_THUMB_DARK      [UIColor colorWithWhite:0.80f alpha:1.0f]

#define GM_CHECK_BG        [UIColor colorWithWhite:0.07f alpha:1.0f]
#define GM_SEG_ACTIVE      [UIColor colorWithWhite:0.13f alpha:1.0f]
#define GM_WARNING         [UIColor colorWithRed:1.0f green:0.8f blue:0.0f alpha:1.0f]

// ─── Tab IDs ─────────────────────────────────────────────────────────────────
typedef NS_ENUM(NSInteger, GMTab) {
    GMTabESP = 0,
    GMTabAimbot,
    GMTabMSL,
    GMTabMISC,
    GMTabUI,
    GMTabSettings,
};

@class GMToggleRow;
@class GMSliderRow;
@class GMSegmentRow;

// ─── GMToggleRow ─────────────────────────────────────────────────────────────
@interface GMToggleRow : UIView
@property (nonatomic, assign) BOOL isOn;
@property (nonatomic, assign) BOOL useCircleStyle;   // NO = checkmark, YES = pill
@property (nonatomic, copy)   NSString *title;
@property (nonatomic, copy)   NSString *subtitle;    // nullable
@property (nonatomic, copy)   void (^onToggle)(BOOL isOn);
- (instancetype)initWithTitle:(NSString *)title
                     subtitle:(NSString *)subtitle
                          isOn:(BOOL)isOn
                  circleStyle:(BOOL)circle
                      isDark:(BOOL)dark;
- (void)applyTheme:(BOOL)dark;
@end

// ─── GMSliderRow ─────────────────────────────────────────────────────────────
@interface GMSliderRow : UIView
@property (nonatomic, assign) float value;
@property (nonatomic, copy)   void (^onValueChange)(float value);
- (instancetype)initWithTitle:(NSString *)title
                          min:(float)min
                          max:(float)max
                         step:(float)step
                        value:(float)value
                       isDark:(BOOL)dark;
- (void)applyTheme:(BOOL)dark;
@end

// ─── GMSegmentRow ────────────────────────────────────────────────────────────
@interface GMSegmentRow : UIView
@property (nonatomic, assign) NSInteger selectedIndex;
@property (nonatomic, copy)   void (^onSelect)(NSInteger index);
- (instancetype)initWithOptions:(NSArray<NSString *> *)options
                  selectedIndex:(NSInteger)index
                          label:(NSString *)label
                         isDark:(BOOL)dark;
- (void)applyTheme:(BOOL)dark;
@end

// ─── GMMenuViewController ────────────────────────────────────────────────────
@interface GMMenuViewController : UIViewController
@property (nonatomic, assign) BOOL isDark;
+ (instancetype)sharedController;
- (void)show;
- (void)dismiss;
@end

// ─── GMMenuWindow ────────────────────────────────────────────────────────────
@interface GMMenuWindow : UIWindow
+ (instancetype)sharedWindow;
- (void)show;
- (void)hide;
@end
