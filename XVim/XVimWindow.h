//
//  XVimWindow.h
//  XVim
//
//  Created by Tomas Lundell on 9/04/12.
//

#import <Cocoa/Cocoa.h>
#import "XVimCommandLine.h"
#import "XVimTextViewProtocol.h"
#import "XVimKeyStroke.h"

/*
 * This class manages 1 window. (The term "window" here is different from NSWindow)
 * A window has several text views and one command line view.
 * All the key input (or mouse input or some other event if needed ) must be passed to
 * the associated XVimWindow object first and it handles the event.
 */

@class XVimSourceView;
@class XVimEvaluator;
@class XVimRegister;
@class IDEEditorArea;
@class IDEWorkspaceWindow;
@class XVimEvaluatorContext;
@class IDEEditorArea;

@interface XVimWindow : NSObject <NSTextInputClient, NSTextFieldDelegate>
@property(readonly) NSTextView *sourceView; // This represents currently focused sourceView
@property(readonly) XVimCommandLine *commandLine;

- (instancetype)initWithIDEEditorArea:(IDEEditorArea *)editorArea;

- (void)handleKeyStroke:(XVimKeyStroke*)keyStroke onStack:(NSMutableArray*)stack;
- (BOOL)handleKeyEvent:(NSEvent*)event;
- (NSRect)drawInsertionPointInRect:(NSRect)rect color:(NSColor*)color;

- (void)errorMessage:(NSString *)message ringBell:(BOOL)ringBell;
- (void)statusMessage:(NSString*)message;
- (void)clearErrorMessage;

- (void)setForcusBackToSourceView;

- (IDEWorkspaceWindow*)currentWorkspaceWindow;

- (void)syncEvaluatorStack;

@end
