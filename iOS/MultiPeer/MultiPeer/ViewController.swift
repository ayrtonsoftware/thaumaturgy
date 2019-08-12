//
//  ViewController.swift
//  MultiPeer
//
//  Created by Michael Bergamo on 4/6/19.
//  Copyright © 2019 Michael Bergamo. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    @IBOutlet var log: UITextView!
    var factService: FactService?
    
    @IBAction func onSend() {
        factService?.send()
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        factService = FactService(log: log)
    }
}

