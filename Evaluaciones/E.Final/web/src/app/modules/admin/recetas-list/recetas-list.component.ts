import { Component, OnInit } from '@angular/core';
import { ActivatedRoute } from '@angular/router';
import { RecetasService } from '../../../services/recetas.service';

@Component({
  selector: 'app-recetas-list',
  templateUrl: './recetas-list.component.html',
  styleUrls: ['./recetas-list.component.scss']
})
export class RecetasListComponent implements OnInit {
  public rs: any;

  constructor(private rService: RecetasService, private route: ActivatedRoute) {
    this.rs = [];
  }

  ngOnInit() {
    this.rService.getRs().subscribe((response: any) => {
      this.rs = response.items;
    });
  }
}
