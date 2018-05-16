import { Component, OnInit } from '@angular/core';
import { ActivatedRoute, Router } from '@angular/router';
import { RecetasService } from '../../../services/recetas.service';

@Component({
  selector: 'app-recetas-item',
  templateUrl: './recetas-item.component.html',
  styleUrls: ['./recetas-item.component.scss']
})
export class RecetasItemComponent implements OnInit {
  public id: string;
  public r: any;

  constructor(
    private route: ActivatedRoute,
    private router: Router,
    private rService: RecetasService
  ) {
    this.r = {};
  }

  ngOnInit() {
    this.id = this.route.snapshot.params['id'];
    this.rService.getR(this.id).subscribe((response: any) => {
      this.r = response.item;
    });
  }

  deleteR() {
    this.rService.deleteR(this.id).subscribe(() => {
      this.router.navigateByUrl('/admin/recetas/list');
    });
  }
}
