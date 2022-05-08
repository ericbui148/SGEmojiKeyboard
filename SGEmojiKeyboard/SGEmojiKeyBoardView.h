//
//  SGEmojiKeyboardView.h
//  SGEmojiKeyboard
//
//  Created by Ayush on 09/05/13.
//  Update by Eric B on 2022-05-07.
//  Copyright (c) 2022 Eric B. All rights reserved.
//
// Set as inputView to textfields, this view class gives an
// interface to the user to enter emoji characters.

#import <UIKit/UIKit.h>
#import <MultiSelectSegmentedControl/MultiSelectSegmentedControl-Swift.h>
typedef NS_ENUM(NSInteger, SGEmojiKeyboardViewCategoryImage) {
    SGEmojiKeyboardViewCategoryImageRecent,
    SGEmojiKeyboardViewCategoryImageEmoji,
    SGEmojiKeyboardViewCategoryImageEmji,
    SGEmojiKeyboardViewCategoryImageTho,
    SGEmojiKeyboardViewCategoryImageRick,
    SGEmojiKeyboardViewCategoryImageKK,
    SGEmojiKeyboardViewCategoryImageFB,
    SGEmojiKeyboardViewCategoryImageDog,
    SGEmojiKeyboardViewCategoryImageCongrat,
    SGEmojiKeyboardViewCategoryImageCC
};

@protocol SGEmojiKeyboardViewDelegate;
@protocol SGEmojiKeyboardViewDataSource;

/**
 Keyboard class to present as an alternate.
 This keyboard presents the emojis supported by iOS.

 @note To modify appearance, use @p segmentsBar @p pageControl
 @p emojiPagesScrollView properties.
 */
@interface SGEmojiKeyboardView : UIView

/**
 Segment control displays the categories.
 */
@property (nonatomic, readonly) MultiSelectSegmentedControl *segmentsBar;

/**
 Pagecontrol displays the current page and number of pages on an emoji page.
 */
@property (nonatomic, readonly) UIPageControl *pageControl;

/**
 Scroll view displays all the emoji pages.
 */
@property (nonatomic, readonly) UIScrollView *emojiPagesScrollView;

@property (nonatomic, weak) id<SGEmojiKeyboardViewDelegate> delegate;
@property (nonatomic, weak) id<SGEmojiKeyboardViewDataSource> dataSource;

/**
 @param frame Frame of the view to be initialised with.

 @param dataSource dataSource is required during the initialization to
 get all the relevent images to present in the view.
 */
- (instancetype)initWithFrame:(CGRect)frame
                   dataSource:(id<SGEmojiKeyboardViewDataSource>)dataSource;

@end


/**
 Protocol to be followed by the dataSource of `SGEmojiKeyboardView`.
 */
@protocol SGEmojiKeyboardViewDataSource <NSObject>

/**
 Method called on dataSource to get the category image when selected.

 @param emojiKeyboardView EmojiKeyBoardView object on which user has tapped.

 @param category category to get the image for. @see SGEmojiKeyboardViewCategoryImage
 */
- (UIImage *)emojiKeyboardView:(SGEmojiKeyboardView *)emojiKeyboardView
      imageForSelectedCategory:(SGEmojiKeyboardViewCategoryImage)category;

/**
 Method called on dataSource to get the category image when not-selected.

 @param emojiKeyboardView EmojiKeyBoardView object on which user has tapped.

 @param category category to get the image for. @see SGEmojiKeyboardViewCategoryImage
 */
- (UIImage *)emojiKeyboardView:(SGEmojiKeyboardView *)emojiKeyboardView
   imageForNonSelectedCategory:(SGEmojiKeyboardViewCategoryImage)category;

/**
 Method called on dataSource to get the back button image to be shown in the view.

 @param emojiKeyboardView EmojiKeyBoardView object on which user has tapped.
 */
- (UIImage *)backSpaceButtonImageForEmojiKeyboardView:(SGEmojiKeyboardView *)emojiKeyboardView;

@optional

/**
 Method called on dataSource to get category that should be shown by
 default i.e. when the keyboard is just presented.

 @note By default `SGEmojiKeyboardViewCategoryImageRecent` is shown.

 @param emojiKeyboardView EmojiKeyBoardView object shown.
 */
- (SGEmojiKeyboardViewCategoryImage)defaultCategoryForEmojiKeyboardView:(SGEmojiKeyboardView *)emojiKeyboardView;

/**
 Method called on dataSource to get number of emojis to be maintained in
 recent category.

 @note By default `50` is used.

 @param emojiKeyboardView EmojiKeyBoardView object shown.
 */
- (NSUInteger)recentEmojisMaintainedCountForEmojiKeyboardView:(SGEmojiKeyboardView *)emojiKeyboardView;

@end


/**
 Protocol to be followed by the delegate of `SGEmojiKeyboardView`.
 */
@protocol SGEmojiKeyboardViewDelegate <NSObject>

/**
 Delegate method called when user taps an emoji button

 @param emojiKeyBoardView EmojiKeyBoardView object on which user has tapped.

 @param emoji Emoji used by user
 */
- (void)emojiKeyBoardView:(SGEmojiKeyboardView *)emojiKeyBoardView
              didUseEmoji:(NSString *)emoji;

/**
 Delegate method called when user taps on the backspace button

 @param emojiKeyBoardView EmojiKeyBoardView object on which user has tapped.
 */
- (void)emojiKeyBoardViewDidPressBackSpace:(SGEmojiKeyboardView *)emojiKeyBoardView;

@end
