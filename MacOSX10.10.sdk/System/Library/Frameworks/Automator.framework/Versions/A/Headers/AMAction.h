/*	
    AMAction.h
    Copyright (C) 2004-2007, 2014 Apple Inc. All rights reserved.    
    
    Public header file.
*/

#import <Foundation/Foundation.h>
#import <Automator/AMAttributesForAnalyzer.h>

@class NSImage;

// AMAction
// =======


typedef NS_ENUM(NSUInteger, AMLogLevel) {
	AMLogLevelDebug = 0, 
	AMLogLevelInfo = 1, 
	AMLogLevelWarn = 2, 
	AMLogLevelError = 3
};

@interface AMAction : NSObject 
{
@private
    NSMutableDictionary *_definition;
    AM_UNUSED_FOR_ANALYZER NSDictionary *_argumentsWithOutlets;
    NSString *_currentInput;
    NSString *_error;
    NSString *_output;
    id _currentRunner;
    AMAction *_loopParent;
	NSString *_actionDescription;
	NSImage *_icon;
	NSUInteger _relevance;
	BOOL _showsRelevance;
	BOOL _stopped;
		
	id _future;
	id _future2;
	id _future3;
	id _future4;
}

// Construction
- (instancetype)initWithDefinition:(NSDictionary *)dict fromArchive:(BOOL)archived;
- (instancetype)initWithContentsOfURL:(NSURL *)fileURL error:(NSError **)outError AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER;

// Accessors
#ifndef __LP64__
- (NSMutableDictionary *)definition AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER_BUT_DEPRECATED;
#endif

@property (readonly, strong) NSString *name AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER;
@property (readonly) BOOL ignoresInput AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER;

// The selected[Input, Output]Type must be a UTI in the action's Info.plist.  Set these to nil to restore default behavior.
@property (strong) NSString *selectedInputType AVAILABLE_MAC_OS_X_VERSION_10_6_AND_LATER;
@property (strong) NSString *selectedOutputType AVAILABLE_MAC_OS_X_VERSION_10_6_AND_LATER;

// Values from 0 to 1 are used to show or determinate progress
@property CGFloat progressValue AVAILABLE_MAC_OS_X_VERSION_10_6_AND_LATER;

// Operations
- (id)runWithInput:(id)input fromAction:(AMAction *)anAction error:(NSDictionary **)errorInfo AVAILABLE_MAC_OS_X_VERSION_10_4_AND_LATER_BUT_DEPRECATED;
- (id)runWithInput:(id)input error:(NSError **)error AVAILABLE_MAC_OS_X_VERSION_10_7_AND_LATER;

- (void)runAsynchronouslyWithInput:(id)input AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER;

- (void)willFinishRunning AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER;
- (void)didFinishRunningWithError:(NSDictionary *)errorInfo AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER_BUT_DEPRECATED;
- (void)finishRunningWithError:(NSError *)error AVAILABLE_MAC_OS_X_VERSION_10_7_AND_LATER;

@property (strong) id output AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER;

- (void)stop;
- (void)reset;
- (void)writeToDictionary:(NSMutableDictionary *)dictionary;

- (void)opened;
- (void)activated;
- (void)closed AVAILABLE_MAC_OS_X_VERSION_10_5_AND_LATER;

- (void)updateParameters;
- (void)parametersUpdated;

- (void)logMessageWithLevel:(AMLogLevel)level format:(NSString *)format, ... NS_FORMAT_FUNCTION (2,3) AVAILABLE_MAC_OS_X_VERSION_10_7_AND_LATER;

@property (getter=isStopped, readonly) BOOL stopped;

@end
