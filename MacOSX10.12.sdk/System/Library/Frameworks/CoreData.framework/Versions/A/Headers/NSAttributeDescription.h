/*
    NSAttributeDescription.h
    Core Data
    Copyright (c) 2004-2016, Apple Inc.
    All rights reserved.
*/

#import <Foundation/NSArray.h>
#import <CoreData/NSPropertyDescription.h>

NS_ASSUME_NONNULL_BEGIN

@class NSEntityDescription;

// types explicitly distinguish between bit sizes to ensure data store independence of the underlying operating system


typedef NS_ENUM(NSUInteger, NSAttributeType) {
    NSUndefinedAttributeType = 0,
    NSInteger16AttributeType = 100,
    NSInteger32AttributeType = 200,
    NSInteger64AttributeType = 300,
    NSDecimalAttributeType = 400,
    NSDoubleAttributeType = 500,
    NSFloatAttributeType = 600,
    NSStringAttributeType = 700,
    NSBooleanAttributeType = 800,
    NSDateAttributeType = 900,
    NSBinaryDataAttributeType = 1000,
    NSTransformableAttributeType API_AVAILABLE(macosx(10.5), ios(3.0)) = 1800, // If your attribute is of NSTransformableAttributeType, the attributeValueClassName must be set or attribute value class must implement NSCopying.
    NSObjectIDAttributeType API_AVAILABLE(macosx(10.6), ios(3.0)) = 2000
 };

// Attributes represent individual values like strings, numbers, dates, etc.
API_AVAILABLE(macosx(10.4),ios(3.0))
@interface NSAttributeDescription : NSPropertyDescription {
#if (!__OBJC2__)
@private
	Class _attributeValueClass;
	NSString *_valueTransformerName;
    NSAttributeType _type;
    NSString *_attributeValueClassName;
    struct __attributeDescriptionFlags {
		unsigned int _hasMaxValueInExtraIvars:1;
		unsigned int _hasMinValueInExtraIvars:1;
		unsigned int _storeBinaryDataExternally:1;
        unsigned int _reservedAttributeFlagOne:1;
        unsigned int _reservedAttributeDescription:28;
    } _attributeDescriptionFlags;
    id _defaultValue;
#endif
}

// NSUndefinedAttributeType is valid for transient properties - Core Data will still track the property as an id value and register undo/redo actions, etc. NSUndefinedAttributeType is illegal for non-transient properties.
@property () NSAttributeType attributeType;

@property (nullable, copy) NSString *attributeValueClassName;

@property (nullable, retain) id defaultValue;   // value is retained and not copied

/* Returns the version hash for the attribute.  This value includes the versionHash information from the NSPropertyDescription superclass, and the attribute type.*/
@property (readonly, copy) NSData *versionHash API_AVAILABLE(macosx(10.5),ios(3.0));

/* The name of the transformer used to convert a NSTransformedAttributeType.  The transformer must output NSData from transformValue and allow reverse transformation.  If this value is not set, or set to nil, Core Data will default to using a transformer which uses NSCoding to archive/unarchive the attribute value.*/
@property (nullable, copy) NSString *valueTransformerName API_AVAILABLE(macosx(10.5),ios(3.0));

@property () BOOL allowsExternalBinaryDataStorage API_AVAILABLE(macosx(10.7),ios(5.0));

@end

NS_ASSUME_NONNULL_END
