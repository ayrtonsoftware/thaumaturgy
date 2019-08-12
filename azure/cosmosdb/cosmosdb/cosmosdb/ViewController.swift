//
//  ViewController.swift
//  cosmosdb
//
//  Created by Michael Bergamo on 4/6/19.
//  Copyright © 2019 Michael Bergamo. All rights reserved.
//

import UIKit
import AzureCore
import AzureData

//final class CosmosFact: Document {
//    static let partitionKey: PartitionKey?  = \.partitionKey
//
//    var id: String
//    var guid: String = ""
//    var category: String = ""
//    var substrings: [String] = []
//    var partitionKey: String = ""
//
//    init(category: String) {
//        self.partitionKey = "Me"
//        self.guid = UUID().uuidString
//        self.id = self.guid
//        self.category = category
//        self.substrings = []
//    }
//}
final class CosmosFact: Document {
    static let partitionKey: PartitionKey?  = \.partitionKey
    
    var id: String
    var guid: String = ""
    var category: String = ""
    var subFacts_Strings: [String] = []
    var subFacts_Ints: [Int] = []
    var subFacts_Double: [Double] = []
    var subFacts_Float: [Float] = []
    var subFacts_Bool: [Bool] = []
    var subFacts_Data: [Data] = []
    var subFacts_Date: [Date] = []
    var partitionKey: String = ""
    
    init(category: String) {
        self.partitionKey = "Me"
        self.guid = UUID().uuidString
        self.id = self.guid
        self.category = category
        self.subFacts_Strings = []
        self.subFacts_Ints = []
        self.subFacts_Double = []
        self.subFacts_Float = []
        self.subFacts_Bool = []
        self.subFacts_Data = []
        self.subFacts_Date = []
    }
}


class ViewController: UIViewController {

    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        
         AzureData.configure(forAccountNamed: "faq", withMasterKey: "lOuP506lM51twlvljksFXuXAV8tlU8bN1rYgXaGr55SmA5SydxBw6ej8oVpNnvdyJ0ofnhHvmA3Z2nipmFMnZw==", withPermissionMode: .all)
        
        AzureData.databases { r in
            if let databases = r.resource?.items {
                print(databases)
                
                if let database = databases.first {
                    AzureData.get (collectionsIn: database) { r in
                        if let collections = r.resource?.items {
                            print(collections)
                            if let collection = collections.first {
                                let create = true
                                let list = false
                                
                                if create {
                                    var obj = CosmosFact(category: "Car")
                                    obj.subFacts_Strings.append("New\(Date())")
                                    obj.subFacts_Strings.append("CosmosDB Test")
                                    obj.subFacts_Data.append("Hello".data(using: .utf8)!)
                                    AzureData.create(obj, in: collection, callback: { (response: Response<CosmosFact>) in
                                        if let f = response.resource {
                                            print(f)
                                        } else {
                                            print(response)
                                            if let data = response.data {
                                                var what = String(data: data, encoding: .utf8)
                                                print(what)
                                            }
                                        }
                                    })
                                }
                                
                                if list {
                                    collection.get (documentsAs: CosmosFact.self) { r in
                                        if let data = r.data {
                                            var what = String(data: data, encoding: .utf8)
                                            print(what)
                                            if let items = r.resource?.items {
                                                for fact in items {
                                                    print("------")
                                                    print(fact.category)
                                                    print(fact.subFacts_Strings)
                                                    print(fact.guid)
                                                }
                                            }
                                            print("-----")
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }


}

