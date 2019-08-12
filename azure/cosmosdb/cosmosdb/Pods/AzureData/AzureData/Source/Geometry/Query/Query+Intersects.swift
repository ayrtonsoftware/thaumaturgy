//
//  Query+Intersects.swift
//  AzureData
//
//  Copyright (c) Microsoft Corporation. All rights reserved.
//  Licensed under the MIT License.
//

import Foundation

extension Query {

    // MARK: - Where

    public func `where`(_ property: String, intersects geometry: Geometry) -> Query {
        assert(!whereCalled, "you can only call `where` once, to add more constraints use `and`")

        whereFragment = "ST_INTERSECTS(\(type!).\(property), \(geometry.description)"
        whereCalled = true
        spatialWhereCalled = true

        return self
    }

    // MARK: - And

    public func and(_ property: String, intersects geometry: Geometry) -> Query {
        assert(whereCalled, "must call where before calling and")

        spatialAndFragments.append("ST_INTERSECTS(\(type!).\(property), \(geometry.description))")
        spatialAndCalled = true

        return self
    }
}
